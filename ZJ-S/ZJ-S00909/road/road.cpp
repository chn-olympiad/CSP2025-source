#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const auto N = LONG_LONG_MAX / 100;
long long a[8110][8110];
int main(){
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = N;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (a[u][v] != N) {
			a[u][v] = min(a[u][v], w);
			a[v][u] = a[u][v];
		}
	}
	for (int i = 1; i <= k; i++) {
		
		for (int j = 1; j <= n; j++) {
			
		}
	}
	for (int i = 1; i <= n; i++) {
		int 
	}
	return 0;
}
