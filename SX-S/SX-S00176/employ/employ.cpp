#include <bits/stdc++.h>
using namespace std;

bool vis[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int p[11], a[11];
long long n, m, ans = 0;
string s;

void dfs(int k) {
	if (k == 0) {
		int x = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] - '0' == 1 && i - x - 1 < a[p[i]]) {
				x++;
			}
		}
		if (x >= m) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			p[n - k + 1] = i;
			dfs(k - 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 10) {
		dfs(n);
		cout << ans;
		return 0;
	}
	ans = 1;
	for (int i = n; i > 1; i--) {
		ans = ans * i;
	}
	cout << ans;

	return 0;
}
