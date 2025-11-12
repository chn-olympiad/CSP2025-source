#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
string s;
int c[505];
bool f[505];
int n, m, ans;
void dfs (int x, int p, int cnt) {
	if (cnt == n && n - p >= m) {
		ans++;
	}
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			f[i] = 1;
			if (c[i] > p || s[cnt - 1] == '1') {
				dfs(i, p, cnt + 1);
			} else {
				dfs(i, p + 1, cnt + 1);
			}
			f[i] = 0;
		}
	}
}
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}