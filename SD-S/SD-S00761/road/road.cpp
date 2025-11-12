#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e6 + 10;

int n, m, k;

struct edge{
	int u, v, w;
}e[N];

struct node{
	int u, v, nxt, w;
}g[N];
int cnt, head[N], fa[N], c[N];
bool sp[N], vis[N];
int ans;

inline void add(int u, int v, int w){
	cnt++;
	g[cnt].u = u;
	g[cnt].v = v;
	g[cnt].w = w;
	g[cnt].nxt = head[u];
	head[u] = cnt;
}

inline bool cmp(edge a, edge b){
	return a.w < b.w;
}

inline int find(int x){
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

inline void kruskal(){
	int num = 0;
	sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= m; i++){
		int x = e[i].u;
		int y = e[i].v;
 		if (find(x) != find(y)){
			add(x, y, e[i].w);
			add(y, x, e[i].w);
			fa[find(x)] = find(y);
			ans += e[i].w;
			num++;
		}
		if (num == n - 1) break;
	}
	return;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		e[i].u = u;
		e[i].v = v;
		e[i].w = w;
	}
	if (k == 0){
		kruskal();
		cout << ans;
		return 0;
	}
	return 0;
}
/*
4 4 0
1 3 5
1 2 4
1 4 1
3 2 1
*/
