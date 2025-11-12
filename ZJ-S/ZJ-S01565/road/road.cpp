#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l),qwp=(r);i<=qwp;i++)
#define per(i,r,l) for(int i=(r),qwp=(l);i>=qwp;i--)
#define pb push_back
#define clr clear
using namespace std;
namespace ax_by_c{
typedef long long ll;
constexpr int N=1e4+15;
constexpr int M=1e6+5;
constexpr int K=12;
int frint(){int n=0;char c=getchar();while(c<'0'||'9'<c)c=getchar();while('0'<=c&&c<='9')n=n*10+c-48,c=getchar();return n;}
void wrll(ll x){if(x>9)wrll(x/10);putchar(x%10+48);}
struct DSU{
    struct node{int fa,sz;}a[N];
    void Init(int n){rep(i,1,n)a[i]={i,1};}
    int find(int x){return (a[x].fa==x)?(x):(a[x].fa=find(a[x].fa));}
    bool meg(int x,int y){
        x=find(x),y=find(y);if(x==y)return 0;
        if(a[x].sz<a[y].sz)swap(x,y);
        a[y].fa=x,a[x].sz+=a[y].sz;
        return 1;
    }
}dsu;
int n,m,k,c[K],idx;ll ans;
struct Edge{int u,v,w;};Edge es[M],e[N*K];
bool cmp(Edge x,Edge y){return x.w<y.w;}
void main(){
    n=frint(),m=frint(),k=frint();
    rep(i,1,m)es[i].u=frint(),es[i].v=frint(),es[i].w=frint();
    sort(es+1,es+1+m,cmp);
    dsu.Init(n);rep(i,1,m)if(dsu.meg(es[i].u,es[i].v))e[++idx]=es[i],ans+=es[i].w;
    rep(i,1,k){c[i]=frint();rep(j,1,n){int x;x=frint();e[++idx]={n+i,j,x};}}
    sort(e+1,e+1+idx,cmp);
    rep(s,1,(1<<k)-1){
        dsu.Init(n+k);
        ll res=0;bool F=0;
        rep(i,1,k)if(s&(1<<(i-1)))res+=c[i];
        rep(i,1,idx){
            if((e[i].u<=n)||(s&(1<<(e[i].u-n-1))))if(dsu.meg(e[i].u,e[i].v))res+=e[i].w;
            if(res>=ans){F=1;break;}
        }
        if(!F)ans=min(ans,res);
    }
    wrll(ans),putchar('\n');
}
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ax_by_c::main();
    return 0;
}
/*
ulimit -s 524288
g++ -O2 -std=c++14 -static road.cpp -o road.exe
g++ -O2 -std=c++14 -static -Wall -Wextra road.cpp -o road.exe
g++ -O2 -std=c++14 -Wall -Wextra -fsanitize=address,leak,undefined road.cpp -o road.exe
./road.exe
*/