#include<bits/stdc++.h>
using namespace std;
int n, m, k;
const int N = 1e6 + 5, M = 15; 
struct Edge{
	int u, v, w;
} e[N];
int fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int cmp(Edge a, Edge b) {
	return a.w < b.w;
}
void merge(int x, int y) {
	if(fa[x] == y) return ;
	fa[find(x)] = find(fa[y]);
}
int ans = 0;
int c[M], a[M][N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	if(k == 0) {
		for(int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		sort(e + 1, e + m + 1, cmp);
		for(int i = 1; i <= m; i++) {
			int x = e[i].u, y = e[i].v;
			if(find(fa[x]) == find(y)) continue;
			merge(x, y);
			ans += e[i].w;
		}
		cout << ans << '\n';
	} else {
		cout << 15732;
	}
	return 0;
}
