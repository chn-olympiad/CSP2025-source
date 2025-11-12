#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m;
string s;
int a[50000];
int c[50000];
int h[100];
int f[100];
int ans = 0;
int fac[1000];

void dfs(int x) {
	if (x == n + 1) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (sum >= c[h[i]] || !a[i]) {
				sum++;
			}
		}
		if (n - sum >= m) {
			ans++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			f[i] = 1;
			h[x] = i;
			dfs(x + 1);
			f[i] = 0;
		}
	}
}
bool opt = true;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
		if (a[i] == 0)
			opt = false;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	if (n <= 10) {
		dfs(1);
		cout << ans % mod;
	} else if (m == n) {
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) {
				opt = false;
			}
		}
		if (opt)
			cout << fac[n];
		else
			cout << 0;
	}
}
