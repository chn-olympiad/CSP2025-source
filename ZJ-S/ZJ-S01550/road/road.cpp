#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 7, N = 1e4 + 7;
struct bian {
	int u, v, w;	
} bn[M];
struct cun {
	int w, v[N];
} cn[15];
bool cmp (bian a, bian b) {
	return a.w < b.w;
}
int fa[N];
int find (int x) {
	if (x == fa[x]) return x;
	return fa[x] = find (fa[x]);
}
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i ++ ) {
		cin >> bn[i].u >> bn[i].v >> bn[i].w;
	}
	for (int i = 0; i < k; i ++ ) {
		cin >> cn[i].w;
		for (int j = 0; j < n; j ++ ) {
			cin >> cn[i].v[j];
		}
	}
	if (k == 0) {
		for (int i = 0; i <= n; i ++ ) {
			fa[i] = i;
		}
		long long s = 0;
		sort (bn, bn + m, cmp);
		for (int i = 0; i < m; i ++ ) {
			if (find (bn[i].u) != find (bn[i].v)) {
				s += bn[i].w;
				fa[bn[i].u] = find (bn[i].v);
			}
		}
		cout << s;
	}
	
	return 0;
}
/*
4 4 0
1 2 1
2 3 3
3 4 5
1 4 10

*/
