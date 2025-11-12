#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+20,M = 2e6+10;
struct Edge{int u,v;ll w;inline bool operator < (const Edge &x) const{return w < x.w;}}e[M],G[M];
int n,m,k,f[N],siz[N],len,tot,Lowbit[M];ll ans,tmp;
struct Item{int id;ll a;inline bool operator < (const Item &x) const{return a < x.a;}}arr[15][N];
inline int find(int x){return (f[x] == x ? x : f[x] = find(f[x]));}
inline bool merge(int u,int v){
	int x = find(u),y = find(v);
	if(x == y) return 0;
	if(siz[x] > siz[y]) swap(x,y);
	f[x] = y;siz[y] += siz[x];
	return 1;
}int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0;i <= k;++i) Lowbit[(1ll<<i)] = i;
	for(int i = 1;i <= n+k;++i) f[i] = i,siz[i] = 1;
	for(int i = 1;i <= m;++i){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}for(int i = 1;i <= k;++i){
		for(int j = 0;j <= n;++j) cin >> arr[i][j].a,arr[i][j].id = j;
		sort(arr[i]+1,arr[i]+1+n);
	}sort(e+1,e+1+m);
	for(int i = 1;i <= m;++i){
		if(merge(e[i].u,e[i].v)){
			ans += e[i].w;G[++len] = e[i];
		}
	}for(int s = 1;s < (1ll<<k);++s){
		tmp = 0;tot = len;
		for(int tmps = s;tmps;tmps -= (tmps&(-tmps))){
			int i = Lowbit[tmps&(-tmps)]+1;
			tmp += arr[i][0].a;int lastot = tot;
			for(int j = 1;j <= n;++j) G[++tot] = (Edge){n+i,arr[i][j].id,arr[i][j].a};
			inplace_merge(G+1,G+lastot+1,G+tot);
		}for(int i = 1;i <= n+k;++i) f[i] = i,siz[i] = 1;
		for(int i = 1;i <= tot;++i){
			if(merge(G[i].u,G[i].v)){
				tmp += G[i].w;
			}
		}ans = min(ans,tmp);len = 0;
		for(int i = 1;i <= tot;++i){
			if(G[i].u <= n) e[++len] = G[i];
		}for(int i = 1;i <= len;++i) G[i] = e[i];
	}cout << ans << "\n";
	return 0;
}