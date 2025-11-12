#include<bits/stdc++.h>
#define INF 0x7fffffff
//#define int long long
typedef long long ll;
using namespace std;
bool st;
const ll MOD=1e15+7;
const ll multi=37;
const int N=6e6+6;
int n,m;
string s1,s2;
int trie[N][27],fail[N],tot=0,total=0,leng=0;
ll iden[30];
vector<ll> tag[N];
vector<int> point[N];
ll number[N];
inline bool cmp(int x,int y){return x>y;}
#define mid ((l+r)>>1)
struct segmentTree{
    int root[N<<2],poi=0;
    int lson[N<<2],rson[N<<2],sum[N<<2];
    void change(int &o1,int o2,int l,int r,int x){//o1 for now    o2 for last
        if(!o1) o1=++poi,sum[o1]=sum[o2];
        //cout<<o1<<" "<<l<<" "<<r<<":"<<sum[o1]<<endl;
        if(l==r){
            sum[o1]++;
            //cout<<sum[o1]<<"?\n";
            return;
        }
        if(x<=mid) change(lson[o1],lson[o2],l,mid,x);
        else change(rson[o1],rson[o2],mid+1,r,x);
        if(!rson[o1]) rson[o1]=rson[o2];
        if(!lson[o1]) lson[o1]=lson[o2];
        sum[o1]=sum[lson[o1]]+sum[rson[o1]];
        //sum[o1]+=sum[o2];
        //cout<<o1<<" "<<sum[o1]<<"?\n";
    }
    int query(int o,int l,int r,int x){
        //cout<<o<<" "<<l<<" "<<r<<":"<<sum[o]<<endl;
        if(l==r) return sum[o];
        if(x<=mid) return query(lson[o],l,mid,x);
        else return query(rson[o],mid+1,r,x);
    }
}T;
#undef mid
ll getval(string st1,string st2){
    int st=-1,en=-1,len=st1.length();
    st1=" "+st1; st2=" "+st2;
    for(int i=1;i<=len;i++){
        if(st1[i]!=st2[i]){st=i;break;}
    }
    for(int i=len;i>=1;i--){
        if(st1[i]!=st2[i]){en=i;break;}
    }
    if(st==-1) return 0;
    ll id1=0,id2=0;
    for(int i=st;i<=en;i++) id1=(id1*multi%MOD+iden[st1[i]-'a'])%MOD;
    for(int i=st;i<=en;i++) id2=(id2*multi%MOD+iden[st2[i]-'a'])%MOD;
    return (id2-id1+MOD)%MOD;
}
void insrt(string st,ll val){
    int u=0,len=st.length(); st=" "+st;
    for(int i=1;i<=len;i++){
        int alph=st[i]-'a';
        if(!trie[u][alph]) trie[u][alph]=++tot,point[i].push_back(tot);
        u=trie[u][alph];
    }
    tag[u].push_back(val);
    number[++total]=val;
}
void AC(int u){
    for(int i=0;i<26;i++){
        if(!trie[u][i]) trie[u][i]=trie[fail[u]][i];
        else{
            fail[trie[u][i]]=trie[fail[u]][i];
            AC(trie[u][i]);
        }
    }
}
int getans(string s,int qaq){
    int len=s.length(),u=0,res=0;
    s=" "+s;
    for(int i=1;i<=len;i++){
        int alph=s[i]-'a';
        u=trie[u][alph];
        //cout<<u<<":"<<T.root[u]<<" ans of querying is "<<T.query(T.root[u],1,leng,qaq)<<endl;
        //cout<<"fail is "<<fail[u]<<endl;
        res+=T.query(T.root[u],1,leng,qaq);
    }return res;
}
bool en;
signed main(){
    //printf("%.3lf",(&en-&st)/1024.0/1024.0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    iden[0]=1;
    for(int i=1;i<26;i++) iden[i]=iden[i-1]*2%MOD+1;
    scanf("%d%d",&n,&m);
    int maxlen=0;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2; maxlen=max(maxlen,(int)s1.length());
        ll val=getval(s1,s2);
        insrt(s1,val);
    }

    sort(number+1,number+total+1);
    leng=unique(number+1,number+total+1)-number;
    for(int i=1;i<=tot;i++){
        for(int j=0;j<tag[i].size();j++){
            tag[i][j]=lower_bound(number+1,number+leng+1,tag[i][j])-number;
        }
    }
    //cout<<leng<<endl;
    //for(int i=0;i<26;i++) fail[trie[0][i]]=trie[0][i];
    for(int i=0;i<26;i++) if(trie[0][i]) AC(trie[0][i]);
    for(int aa=1;aa<=maxlen;aa++){
        for(auto i:point[aa]){
            for(auto v:tag[i]){
                int lrc=T.root[i];
                if(lrc) T.root[i]=++T.poi,T.change(T.root[i],lrc,1,leng,v);
                else T.root[i]=++T.poi,T.change(T.root[i],T.root[fail[i]],1,leng,v);
            }
            if(tag[i].empty()) T.root[i]=T.root[fail[i]];
        }
    }

    for(int i=1;i<=m;i++){
        cin>>s1>>s2;
        ll val=getval(s1,s2);
        int qaq=lower_bound(number+1,number+leng+1,val)-number;
        if(number[qaq]!=val){
            printf("0\n");
            continue;
        }
        //cout<<"val of question : "<<qaq<<endl;
        printf("%d\n",getans(s1,qaq));
    }
    return 0;
}
