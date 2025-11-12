#include <bits/stdc++.h>
using namespace std;

int c[505];
bool vis[505], pass[505];
int n, m, cnto;
string s;
long long ans;

void dfs(int dep, int sum, int sad) {
	if (dep > n) {
		if (sum >= m) {
			ans++;
		}
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			if (sad >= c[i] || !pass[dep]) {
				dfs(dep + 1, sum, sad + 1);
			} else {
				dfs(dep + 1, sum + 1, sad);
			}
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		pass[i + 1] = s[i] - '0';
		if (pass[i + 1]) {
			cnto++;
		}
	}
	if (cnto == n) {
		long long ans = 1;
		for (int i = 2; i <= n; i++) {
			ans *= i;
		}
		cout << ans % 998244353;
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans % 998244353;
	return 0;
}
