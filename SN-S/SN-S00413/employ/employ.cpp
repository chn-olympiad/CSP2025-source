#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int n, m, c[505], p[505], v[505], ans, sum[505];
string s;

void dfs(int k) {
	if (k > n) {
		int ou = 0;
		for (int i = 1; i <= n; i++) {
			if (ou >= c[p[i]] || s[i - 1] == '0') {
				ou++;
			}
		}
		if (n - ou >= m) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			p[k] = i;
			v[i] = 1;
			dfs(k + 1);
			v[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	dfs(1);
	cout << ans;
	return 0;
}
