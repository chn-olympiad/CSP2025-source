#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
#define Max(x,y) x = max(x,y)
#define Min(x,y) x = min(x,y)
#define fr(i,l,r) for (i=(l); i<=(r); i++)
#define rfr(i,l,r) for (i=(l); i>=(r); i--)
template<typename T>inline void read(T &n){
    T w = 1; n = 0; char ch = getchar();
    while (!isdigit(ch) && ch!=EOF){
        if (ch=='-') w = -1;
        ch = getchar();
    }
    while (isdigit(ch) && ch!=EOF){
        n = n*10 + ch-'0';
        ch = getchar();
    }
    n *= w;
}
const ll N = 10105, M = 1000005, K = 12;
ll n,m,k,ans;
struct edge{
    ll x,y,w;
    bool operator < (const edge o)const{ return w<o.w; }
};
edge e[N], ee[M];
struct Union_Find{
    int fa[N];
    void init(int n){
        int i;
        fr(i,0,n+1) fa[i] = i;
    }
    int find(int x){
        if (fa[x]==x) return x;
        else return fa[x] = find(fa[x]);
    }
    bool merge(int x,int y){
        x = find(x), y = find(y);
        if (x==y) return false;
        fa[x] = y;
        return true;
    }
}uf;
struct Graph{
	ll sum;
    edge e[N];
    void clear(){ sum = 0; }
    void ins(edge p){
    	e[++sum] = p;
	}
    ll calc(){
        ll i, ans = 0;
        fr(i,1,sum) ans += e[i].w;
        return ans;
    }
}f[K], a[K];
ll c[K];
void merge(Graph &f,Graph &g,Graph &h){
    ll i = 1, j = 1;
    h.clear();
    uf.init(n+k);
    while (i<=f.sum || j<=g.sum){
        edge p;
        if ( j>g.sum || (i<=f.sum && f.e[i].w<g.e[j].w) ) p = f.e[i++];
        else p = g.e[j++];
        if (uf.merge(p.x,p.y)) h.ins(p);
    }
}
void dfs(ll x,ll v){
    if (x>k){ Min(ans,f[x-1].calc()+v); return ; }
    f[x] = f[x-1], dfs(x+1,v);
    merge(f[x-1],a[x],f[x]), dfs(x+1,v+c[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll i,j;
    read(n), read(m), read(k);
    fr(i,1,m) read(ee[i].x), read(ee[i].y), read(ee[i].w);
    sort(ee+1,ee+1+m);
    uf.init(n);
	f[0].clear();
    fr(i,1,m)
        if (uf.merge(ee[i].x,ee[i].y)) f[0].ins(ee[i]);
    fr(i,1,k){
        read(c[i]);
        a[i].clear();
        fr(j,1,n){
            ll x; read(x);
            a[i].ins(edge{n+i,j,x});
        }
        sort(a[i].e+1,a[i].e+1+n);
    }
    ans = inf, dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}
//g++ road.cpp -o a -Wall -O2 -std=c++11