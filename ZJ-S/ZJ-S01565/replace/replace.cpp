#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l),qwp=(r);i<=qwp;i++)
#define per(i,r,l) for(int i=(r),qwp=(l);i>=qwp;i--)
#define pb push_back
#define clr clear
#define ins insert
#define umap unordered_map
using namespace std;
namespace ax_by_c{
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,int> ND;
constexpr ll M1=1e9+9;
constexpr ll M2=1145141;
constexpr ll B1=131;
constexpr ll B2=1331;
constexpr int QQQ=2e5+5;
constexpr int L=5e6+5;
constexpr int S=26;
int frint(){int n=0;char c=getchar();while(c<'0'||'9'<c)c=getchar();while('0'<=c&&c<='9')n=n*10+c-48,c=getchar();return n;}
void wrll(ll x){if(x>9)wrll(x/10);putchar(x%10+48);}
inline ll H(pll x){return x.first*M2+x.second;}
inline pll ext(pll x,char y){return {(x.first*B1+y)%M1,(x.second*B2+y)%M2};}
inline pll operator - (pll x,pll y){return {(x.first-y.first+M1)%M1,(x.second-y.second+M2)%M2};}
int n,m,q;char s[L],ss[L];
int idx,son[L][S];vector<pll>hs[L];
int _ins(){int u=0;rep(i,1,m){int &v=son[u][s[i]-'a'];if(!v)v=++idx;u=v;}return u;}
int kmp[L],nxt[L][S];
struct QUEUE{
    int Q[L],ql,qr;
    inline void Init(){ql=1,qr=0;}
    inline void push(int x){Q[++qr]=x;}
    inline void pop(){ql++;}
    inline int front(){return Q[ql];}
    inline bool empty(){return ql>qr;}
}Q;
// vector<int>g[L];
struct LSTNODE{int v,nxt;}g_[L];
int gc_,ghd[L];
inline void pbg(int x,int y){g_[++gc_]={y,ghd[x]},ghd[x]=gc_;}
void bld(){
    Q.Init();
    rep(i,0,25)if(son[0][i])nxt[0][i]=son[0][i],Q.push(son[0][i]);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        rep(i,0,25)nxt[u][i]=((son[u][i])?(son[u][i]):(nxt[kmp[u]][i]));
        rep(i,0,25){
            int v=son[u][i];if(!v)continue;
            kmp[v]=nxt[kmp[u]][i],Q.push(v);
        }
    }
    rep(i,1,idx)pbg(kmp[i],i);
}
vector<ND>qs[L];umap<ll,int>hcnt;ll ans[QQQ];
void dfs(int u){
    for(auto it:hs[u])hcnt[H(it)]++;
    for(auto it:qs[u])if(hcnt.count(H(it.first)))ans[it.second]+=hcnt[H(it.first)];
    for(int i=ghd[u];i;i=g_[i].nxt)dfs(g_[i].v);
    for(auto it:hs[u])if(!(--hcnt[H(it)]))hcnt.erase(hcnt.find(H(it)));
}
void rd(char *qwq){
    m=0;char c=getchar();
    while(c<'a'||'z'<c)c=getchar();
    while('a'<=c&&c<='z')qwq[++m]=c,c=getchar();
}
void main(){
    n=frint(),q=frint();
    rep(_,1,n){
        rd(s);int pos=_ins();pll h1={0,0};rep(i,1,m)h1=ext(h1,s[i]);
        rd(s);pll h2={0,0};rep(i,1,m)h2=ext(h2,s[i]);hs[pos].pb(h2-h1);
    }
    bld();
    rep(_,1,q){
        rd(s);int tm=m;rd(ss);if(m!=tm)continue;
        int pp=m;while(pp>1&&s[pp]==ss[pp])pp--;
        int u=0;pll h1={0,0},h2={0,0};
        rep(i,1,m){
            u=nxt[u][s[i]-'a'],h1=ext(h1,s[i]),h2=ext(h2,ss[i]);
            if(pp<=i)qs[u].pb({h2-h1,_});
        }
    }
    dfs(0);
    rep(i,1,q)wrll(ans[i]),putchar('\n');
}
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ax_by_c::main();
    return 0;
}
/*
ulimit -s 2097152
g++ -O2 -std=c++14 -static replace.cpp -o replace.exe
g++ -O2 -std=c++14 -static -Wall -Wextra replace.cpp -o replace.exe
g++ -O2 -std=c++14 -Wall -Wextra -fsanitize=address,leak,undefined replace.cpp -o replace.exe
./replace.exe
*/