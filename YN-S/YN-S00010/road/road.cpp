#include <bits/stdc++.h>
using namespace std;
long long n, m, k, money[10005][10005], ans, u[1000005], v[1000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= 10000; i++)
		for (int j = 1; j <= 10005; j++) {
			money[i][j] = 2147483647;
		}
	for (int i = 1; i <= m; i++) {
		long long w;
		cin >> u[i] >> v[i] >> w;
		money[u[i]][v[i]] = min(money[u[i]][v[i]], w);
	}
	int flag = 0;
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		if (c != 0) {
			flag = 1;
			break;
		}
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num != 0) {
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0 && k != 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++) {
			money[u[i]][v[i]] = min(money[u[i]][v[i]], money[u[i]][j] + money[j][v[i]]);
		}
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			ans = max(ans, money[i][j]);
	cout << ans;
	return 0;
}