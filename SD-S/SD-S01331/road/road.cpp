#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lowbit(x) x & (-x)
#define pii pair<int, int>
#define INF 0x3f3f3f3f
const int MAXN = 1e4 + 3, sec = 900;
//struct Dij{
//	int dis[MAXN];
//	vector<pii> g[MAXN];
//	void init(int n){
//		for(int i = 1;i <= n;i++){
//			g[i].clear();
//			dis[i] = INF;
//		}
//	}
//	void add(int u, int v, int w){
//		g[u].push_back({v, w});
//	}
//	void solve(int s){
//		dis[s] = 0;
//		priority_queue<pii, vector<pii>, greater<pii>> pq;
//		pq.push({0, s});
//		while(!pq.empty()){
//			pii tp = pq.top();
//			pq.pop();
//			int d = tp.first, u = tp.second;
//			if(d != dis[u]) continue;
//			for(int i = 0;i < g[u].size();i++){
//				int v = g[u][i].first, w = g[u][i].second;
//				if(dis[v] > dis[u] + w){
//					dis[v] = dis[u] + w;
//					pq.push({dis[v], v});
//				}
//			}
//		}
//	}
//};
struct DSU{
	int fa[MAXN];
	void init(int n){
		for(int i = 0;i < n;i++){
			fa[i] = i;
		}
	}
	int find(int x){
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	void merge(int x, int y){
		fa[find(x)] = find(y);
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
};
/*
4 5
1 2 2
1 3 100
2 3 3
2 4 4
3 4 100
*/
int nn, m, k;
int c[MAXN];
int a[MAXN][MAXN];
int n;


	struct Edge{
		int u, v, w;
	};
	vector<Edge> es;
	bool cmpp(Edge a, Edge b){
		return a.w < b.w;
	}
	ll build(){
		sort(es.begin(), es.end(), cmpp);
		DSU dsu;
		dsu.init(n);
		ll res = 0, cnt = 0;
		for(int i = 0;i < n;i++){
			int u = es[i].u, v = es[i].v, w = es[i].w;
			if(!dsu.same(u, v)){
				dsu.merge(u, v);
				res += w;
				if(++cnt == dsu.fa[0]) break;
			}
		}
		return cnt == dsu.fa[0] ? res : -1;
	}
//请注意T3的空间限制 
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	IOS 
//	while(ti - clock() < sec)
	cin >> nn >> m >> k;
	for(int i = 0;i < m;i++){
		cin >> es[i].u >> es[i].v >> es[i].w;
	}
	for(int i = 0;i < k;i++){
		cin >> c[i];
		for(int j = 0;j < nn;j++){
			cin >> a[i][j];
			es[i + nn].u = i;
			es[i + nn].v = j;
			es[i + nn].w = a[i][j];
		}
	}
	cout << 1;
	n = nn + k;
	ll res = build();
	cout << res;
//	cout << "\n\n\n" << 1000 * clock() / CLOCKS_PER_SEC << " ms";
	return 0;
}
