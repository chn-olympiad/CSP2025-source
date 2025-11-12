#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200001][4];
int cnt[4];

int dfs(int id) {
	int ans = 0;

	if (id == n + 1) {
		return 0;
	} else {
		for (int i = 1; i <= 3; i++) {

			if (cnt[i] < (n / 2)) {
				cnt[i]++;
				ans = max(ans, dfs(id + 1) + a[id][i]);
				cnt[i]--;
			}
		}

		return ans;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				cin >> a[i][j];
			}
		}

		cout << dfs(0) << endl;
		memset(a, 0, sizeof(a));
		memset(cnt, 0, sizeof(cnt));
	}

	return 0;
}