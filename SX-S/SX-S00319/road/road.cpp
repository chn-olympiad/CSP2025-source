#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n, m, k, u, vi, w;
int a[15];
vector<vector<int> > v;
bool f[N];
int mi = INT_MAX;

int dfs(int id, int deep, int sum) {
	if (deep > m) {
		mi = min(mi, sum);
		return mi;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (f[v[i][j]] == false && v[i][j] != 0) {
				f[v[i][j]] = true;
				deep++;
				sum += v[i][j];
				dfs(id + 1, deep + 1, sum);
				sum -= v[i][j];
				deep--;
				f[v[i][j]] = false;
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> vi >> w;
		v[u][vi] = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++) {
			cin >> v[n + i][j];
		}
	}
	dfs(1, 0, 0);
	cin >> mi;
	return 0;
}