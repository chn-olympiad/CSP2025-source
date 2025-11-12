#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, k, c[15][10005];
bool A;

vector<int> g[10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
		if (c[i][1] != 0) A = true;
	}
	
	return 0;
}

/*
k = 0：最小生成树 
特殊性质A：城市化改造不花钱，相当于城市结点，同样是最小生成树  
*/
