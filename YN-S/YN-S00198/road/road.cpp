#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;

ll gz[10];
bool flag1[5], flag2[3];
ll cost;
ll minn;
ll map[10001][10001];
void dfs(int t) {
	for (int i = 1; i <= 4; i++) {
		if (!flag1[i])
			break;
		else {
			minn = min(minn, cost);
			return;
		}
	}
	for (int i = 1; i <= m + k; i++) {
		if (map[t][i] && i > m && !flag2[i - m]) {
			cost += gz[i - m];
			flag2[i - m] = true;
		} else
			flag1[i] = true;
		cost += map[t][i];
		dfs(i);
		cost -= map[t][i];
		if (i > m && flag2[i - m]) {
			cost -= gz[i - m];
			flag2[i - m] = false;
		} else
			flag1[i] = false;
	}
}

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		cin >> map[u][v]
	}
	for (int i = 1; i <= k; i++) {
		cin >> gz[i];
		for (int j = 1; j <= n; j++)
			cin >> map[m + i][j];
	}
	for (int i = 1; i <= m + k; i++)
		dfs(i);
	cout << cost;
	return 0;
}