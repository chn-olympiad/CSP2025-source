#include <bits/stdc++.h>
using namespace std;

int n, m, c[501], ans;
string s;
int inter[501];
bool f[501];

void dfs(int p) {
	if (p == n + 1) {
		int lose_cnt = 0, hired = 0;
		for (int i = 1; i <= n; i++) {
			char problem = s[i - 1];
			if (lose_cnt >= c[i]) {
				continue;
			}

			if (problem == '1') {
				hired++;
			}

			else {
				lose_cnt++;
			}
		}

		for (int i = 1; i <= n; i++) {
			cout << inter[i] << " ";
		}

		cout << endl;
		ans += (hired >= m);
		ans %= 998244353;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			f[i] = 1;
			inter[p] = i;
			dfs(p + 1);
		}

		if (f[i]) {
			f[i] = 0;
			dfs(p + 1);
		}
	}

	return;
}

int main() {
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	dfs(1);
	cout << ans % 998244353 << endl;
	return 0;
}