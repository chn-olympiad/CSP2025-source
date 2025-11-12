#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define N 10005
#define M 1000005
struct edge{
	int u,v,w;
}G[M * 2],g[M * 2];
int n,m,k,c[15],a[15][N];
int fa[N * 2];
int id[N * 2];
void init(){
	for(int i = 1; i <= n + k; i++)fa[i] = i;
}
int get(int u){
	if(u == fa[u])return u;
	return fa[u] = get(fa[u]);
}
bool cmp(edge x,edge y){
	return x.w < y.w;
}
bool cmp1(int x,int y){
	return c[x] < c[y];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	init();
	for(int i = 1; i <= m; i++){
		cin >> G[i].u >> G[i].v >> G[i].w;
	}
	int flag = 0;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		if(c[i] != 0)flag = 1;
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
//	cout << k << '\n';
	if(k == 0 || flag == 0){
		int len = m;
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				G[++len].u = n + i;
				G[len].v = j;
				G[len].w = a[i][j];
			}
		}
		sort(G + 1,G + len + 1,cmp);
		i64 ans = 0;
		for(int i = 1; i <= len; i++){
			int U = get(G[i].u);
			int V = get(G[i].v);
			if(U != V){
				ans += G[i].w;
				fa[U] = V;
			}
		}
		cout << ans << endl;
	}else if(m <= 100000 && k <= 5){
		i64 minn = 1e18;
		for(int S = 0; S < (1 << k); S++){
			i64 ans = 0;
			init();
			int len = m;
			for(int i = 1; i <= m; i++){
				g[i].u = G[i].u;
				g[i].v = G[i].v;
				g[i].w = G[i].w;
			}
			for(int i = 1; i <= k; i++){
				if(((S >> (i - 1)) & 1)){
					ans += c[i];
					for(int j = 1; j <= n; j++){
						g[++len].u = n + i;
						g[len].v = j;
						g[len].w = a[i][j];
					}
				}
			}
			sort(g + 1,g + len + 1,cmp);
			for(int j = 1; j <= len; j++){
				int U = get(g[j].u);
				int V = get(g[j].v);
				if(U != V){
					ans += g[j].w;
					fa[U] = V;
				}
			}
			minn = min(minn,ans);
		}
		cout << minn << endl;
	}else{
		i64 minn = 1e18;
		sort(G + 1,G + m + 1,cmp);
		i64 ans = 0;
		for(int i = 1; i <= m; i++){
			int U = get(G[i].u);
			int V = get(G[i].v);
			if(U != V){
				ans += G[i].w;
				fa[U] = V;
			}
		}
		minn = ans;
		for(int i = 1; i <= k; i++)id[i] = i;
		sort(id + 1,id + k + 1,cmp1);
		int len = m;
		for(int i = 1; i <= m; i++){
			g[i].u = G[i].u;
			g[i].v = G[i].v;
			g[i].w = G[i].w;
		}
		i64 sum = 0;
		for(int i = 1; i <= min(6,k); i++){
			init();
			sum += c[id[i]];
			ans = 0;
			for(int j = 1; j <= n; j++){
				g[++len].u = n + id[i];
				g[len].v = j;
				g[len].w = a[id[i]][j];
			}
			sort(g + 1,g + len + 1,cmp);
			for(int j = 1; j <= len; j++){
				int U = get(g[j].u);
				int V = get(g[j].v);
				if(U != V){
					ans += g[j].w;
					fa[U] = V;
				}
			}
			minn = min(minn,ans + sum);
		}
		cout << minn << endl;
	}
	return 0;
}

