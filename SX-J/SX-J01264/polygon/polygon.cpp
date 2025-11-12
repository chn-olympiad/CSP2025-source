#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans, x[5005], ma = 0, cnt = 0;;
bool vis[5005], f[5005];

void dfs(int k, int b) {

	if (k  == b + 1) {
		for (int i = 1; i <= n; i++) {
			if (f[i])
				if (a[i] > ma)
					ma = a[i];

		}
		if (cnt > 2 * ma) {
			//cout << cnt << " " << ma << endl;
			ans++;
			ma = 0;
			cnt = 0;
		}
		return;
	}
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= n; j++) {
			if (vis[j] == 1)
				continue;
			cnt += a[j];
			vis[j] = 1;

			dfs(k + 1, b);
			vis[j] = 0;
			cnt -= a[j];

		}
	}
}

int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int b = 3; b <= n; b++) {
		dfs(1, b);
		memset(f, 0, sizeof(f));
		memset(vis, 0, sizeof(vis));
	}
	cout << ans % 998244353;
	return 0;
}
