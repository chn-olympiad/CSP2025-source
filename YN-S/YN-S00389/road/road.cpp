#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int MAXM = 1000005;

int n, m, k;
int u, v, w;

int c[11];
int a[11][MAXN];

vector<int> connect[MAXN];

int cost[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		connect[u].push_back(v);
		connect[v].push_back(u);
		cost[u][v] = w;
		cost[v][u] = w;
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dp[0][0] = 0;
	return 0;
}