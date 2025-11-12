// #define NDEBUG
#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define ForD(i,j,k) for(int i=(j);i>=(k);i--)
#define ll long long
#define endl '\n'
using namespace std;
bool Mbe;
const int N=2e5+5,M=6e6+5;
const int Bs=13331,mod=998244353;
int ch[M][27];
int vl[M];
map<pair<int,int>,int> mp;
int cnt=0;
void insert(int &rt,int len,int *s){
    if(!rt) rt=++cnt;
    int u=rt;
    For(i,0,len-1){
        if(!ch[u][s[i]]) ch[u][s[i]]=++cnt;
        // cerr<<' '<<u;
        u=ch[u][s[i]];
    }
    vl[u]++;
    // cerr<<' '<<u<<endl;
}
int link[M];
int rt[N];
vector<int> E[M];
bool vis[M];
#define pb emplace_back
void solve(){
    int n,q; cin>>n>>q;
    int tot=0;
    static char s1[M],s2[M];
    static int s[M];
    For(i,1,n){
        cin>>s1>>s2;
        int m=strlen(s1);
        int ptl=0,ptr=m-1;
        while(ptl<m&&s1[ptl]==s2[ptl]) ptl++;
        while(ptr>0&&s1[ptr]==s2[ptr]) ptr--;
        if(ptr<ptl) continue;
        int hsh1=0,hsh2=0;
        For(i,ptl,ptr){
            hsh1=(1ll*hsh1*Bs+s1[i]-'a')%mod;
            hsh2=(1ll*hsh2*Bs+s2[i]-'a')%mod;
        }
        if(!mp[{hsh1,hsh2}]) mp[{hsh1,hsh2}]=++tot;
        int id=mp[{hsh1,hsh2}];
        int len=0;
        For(i,0,ptl-1) s[len++]=s1[i]-'a';
        s[len++]=26;
        For(i,ptr+1,m-1) s[len++]=s1[i]-'a';
        insert(rt[id],len,s);
    }
    static queue<int> Q;
    For(i,1,tot){
        link[rt[i]]=-1;
        For(c,0,26) if(ch[rt[i]][c]) Q.push(ch[rt[i]][c]);
        For(c,0,26){
            if(ch[rt[i]][c]) link[ch[rt[i]][c]]=rt[i];
            else ch[rt[i]][c]=rt[i];
        }
        while(!Q.empty()){
            int u=Q.front(); Q.pop();
            int lk=link[u];
            For(i,0,26){
                if(!ch[u][i]) ch[u][i]=ch[lk][i];
                else{
                    link[ch[u][i]]=ch[lk][i];
                    Q.push(ch[u][i]);
                }
            }
        }
    }
    For(i,1,cnt) E[link[i]].pb(i);
    For(i,1,tot) Q.push(rt[i]);
    while(!Q.empty()){
        int u=Q.front(); Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:E[u]) vl[v]+=vl[u];
        For(i,0,26) if(ch[u][i]&&!vis[ch[u][i]]) Q.push(ch[u][i]);
    }
    For(_,1,q){
        cin>>s1>>s2;
        int m=strlen(s1);
        int ptl=0,ptr=m-1;
        while(ptl<m&&s1[ptl]==s2[ptl]) ptl++;
        while(ptr>0&&s1[ptr]==s2[ptr]) ptr--;
        int hsh1=0,hsh2=0;
        For(i,ptl,ptr){
            hsh1=(1ll*hsh1*Bs+s1[i]-'a')%mod;
            hsh2=(1ll*hsh2*Bs+s2[i]-'a')%mod;
        }
        int id=mp[{hsh1,hsh2}];
        if(!id){
            cout<<0<<endl;
            continue;
        }
        int len=0;
        For(i,0,ptl-1) s[len++]=s1[i]-'a';
        s[len++]=26;
        For(i,ptr+1,m-1) s[len++]=s1[i]-'a';
        int u=rt[id],ans=0;
        For(i,0,len-1){
            // cerr<<' '<<u;
            u=ch[u][s[i]];
            ans+=vl[u];
        }
        // cerr<<' '<<u<<endl;
        cout<<ans<<endl;
    }
}
bool Med;
signed main(){
    fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
    freopen("replace.in","r",stdin), freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--) solve();
    cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}