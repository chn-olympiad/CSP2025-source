#include "bits/stdc++.h"
using namespace std;
vector v;
int n, m, k, citycost[1005][1005], u, v, w, j, x;
bool city[1005];
vector contrycost[10e9+1];

int main() {
	freopen("road1.in", "r", stdin);
	freopen("road1.in", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) { //输入城市与城市之间的路费
		cin >> u >> v;
		cin >> citycost[u][v];
		citycost[v][u] = citycost[u][v];
	}
	for (int i = 1; i <= k; i++) { //输入农村路费和兴起费
		cin >> j;
		for (int o = 1; o <= n; o++) {
			cin >> x;
			contrycost[i].push_back(x);
		}
		contrycost[i].push_back(j);
	}

}