#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
using namespace std;
using ll=long long;
const int N=2e5+10,M=5e6+10,S=26,inf=0x3f3f3f3f;
void read(){}
template<class T,class...T2>
void read(T&ret,T2&...rest){
    ret=0;int c=gc();bool f=0;
    for(;!isdigit(c);c=gc())f=c=='-';
    for(;isdigit(c);c=gc())ret=ret*10+c-'0';
    f&&(ret=-ret),read(rest...);
}
void read(string&s){
    s=" ";char c=gc();
    for(;isspace(c);c=gc());
    for(;isgraph(c);c=gc())s+=c;
}
#define cin(...) read(__VA_ARGS__)
template<class T>
void print(T x){
    static short sta[35],t=0;
    bool f=0;if(x<0)x=-x,f=1;
    do sta[++t]=x%10;while(x/=10);
    for(f&&pc('-');t;)pc(sta[t--]+'0');
}
int n,q,le[N];
string s[2],t[2];
struct ACAM{
    int c=1,to[M][S],lk[M],lk2[M],d[M];
    vector<int>ed[M];
    void ins(int x,int y){
        int u=1;
        for(int i=1;i<=le[x];i++){
            if(!to[u][s[y][i]-'a'])
                d[to[u][s[y][i]-'a']=++c]=d[u]+1;
            u=to[u][s[y][i]-'a'];
        }
        ed[u].pb(x);
    }
    void build(){
        queue<int>q;
        lk[1]=lk2[1]=0;
        for(int i=0;i<S;i++)
            if(to[1][i])
                q.push(to[1][i]),lk[to[1][i]]=lk2[to[1][i]]=1;
        for(int u;!q.empty();q.pop()){
            u=q.front();
            for(int i=0;i<S;i++){
                if(to[u][i]){
                    int v=to[u][i],&w=lk[v];
                    q.push(v),w=lk[u];
                    for(;w>1&&!to[w][i];w=lk[w]);
                    if(to[w][i])w=to[w][i];
                    if(!ed[w].empty())lk2[v]=w;
                    else lk2[v]=lk2[w];
                }
            }
        }
    }
}ac[2];
signed main(){
#ifdef local
    freopen("replace4.in","r",stdin);
    freopen("replace.err","w",stderr);
#else
    freopen("replace.in","r",stdin);
#endif
    freopen("replace.out","w",stdout);
    cin(n,q);
    for(int i=1;i<=n;i++){
        for(int j:{0,1})cin(s[j]);
        le[i]=(int)s[0].size()-1;
        for(int j:{0,1})ac[j].ins(i,j);
    }
    for(int j:{0,1})ac[j].build();
    for(int qi=1;qi<=q;qi++){
        for(int j:{0,1})cin(t[j]);
        if(t[0].size()!=t[1].size()){
            puts("0");
            continue;
        }
        int lx=t[0].size()-1,u[2]={1,1};
        ll res=0;
        int lp=0,rp=0;
        for(int i=1;i<=lx;i++)
            if(t[0][i]!=t[1][i])
                if(rp=i;!lp)lp=i;
        //cerr<<"["<<lp<<","<<rp<<"]\n";
        for(int i=1;i<=lx;i++){
            //cerr<<"! "<<i<<" "<<t[0][i]<<" "<<t[1][i]<<endl;
            for(int j:{0,1}){
                for(;u[j]>1&&!ac[j].to[u[j]][t[j][i]-'a'];)u[j]=ac[j].lk[u[j]];
                if(ac[j].to[u[j]][t[j][i]-'a'])
                    u[j]=ac[j].to[u[j]][t[j][i]-'a'];
            }
            if(i>=rp){
                int x=u[0];
                unordered_set<int>s0;
                //cerr<<"IX:";
                for(;x&&i-ac[0].d[x]+1<=lp;x=ac[0].lk2[x])
                    for(int ix:ac[0].ed[x])s0.insert(ix);//,cerr<<ix<<" ";
                //cerr<<endl;
                //cerr<<"SZ:"<<s0.size()<<endl;
                x=u[1];
                for(;x&&i-ac[1].d[x]+1<=lp;x=ac[1].lk2[x])
                    for(int ix:ac[1].ed[x])
                        if(s0.find(ix)!=s0.end())
                            res++;//,cerr<<"~ "<<ix<<" "<<s0.size()<<endl;
            }
        }
        print(res),pc(endl);
        //break;
        //cout<<t[0]<<" "<<t[1]<<endl;
        //cerr<<"!! "<<qi<<endl;
    }
    return 0;
}
//g++ replace.cpp -o replace -Wall -Wextra -Og -g -std=c++14 -fsanitize=address,undefined -Dlocal