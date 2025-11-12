#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int f[N][3];
int cnt[3];
int g[N];
int n;
int maxn = 0;

void dfs(int k) {
	if (cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2)
		return;
	if (k == n + 1) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += f[i][g[i]];
		}
		for (int i = 1; i <= n; i++) {
			cout << g[i] << " ";
		}
		cout << endl;
		maxn = max(maxn, sum);
		return;
	}
	for (int i = 0; i < 3; i++) {
		cnt[i]++;
		g[k] = i;
		dfs(k + 1);
		cnt[i]--;
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		maxn = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> f[i][j];
			}
		}
		dfs(1);
		cout << maxn << endl;
	}
	return 0;
}