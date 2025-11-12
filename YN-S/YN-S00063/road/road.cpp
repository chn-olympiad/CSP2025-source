#include<bits/stdc++.h>
using namespace std;
bool isvis[10010];
int nd;
int n, m, k;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int cost[n + 2][n + 2];
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			cost[i][j] = 1e9-1;
		}
	}
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			cost[t1][t2] = t3;
			cost[t2][t1] = t3;
		}
		for (int p = 1; p <= n; p++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cost[i][j] = min(cost[i][j], cost[i][p] + cost[j][p]);
				}
			}
		}
		cout << cost[1][n] << endl;
	} else cout << 0 << endl;
	return 0;
}
