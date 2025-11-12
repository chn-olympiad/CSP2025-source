//2025csp-s mzyz ÀîÄ­è°
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int n, m, a[506], b[506], cnt1, cnt0;

ll jie[506] = {1}, ans;
string s;
bool bo[506];

void dfs(int x, int y) {
	if (y >= m) {
		ans += jie[n - x + 1];
		ans %= mod;
		return;
	}
	if (x > n) {
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (bo[i]) {
			continue;
		}
		bo[i] = 1;
		if (s[x - 1] ^ 48) {
			if (x - 1 - y >= a[i]) {
				dfs(x + 1, y);
			} else {
				dfs(x + 1, y + 1);
			}
		} else {
			dfs(x + 1, y);
		}
		bo[i] = 0;
	}
}

int main() {
//	freopen("employ2.in", "r", stdin);
//	freopen("T4.out", "w", stdout);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		jie[i] = jie[i - 1] * i;
		jie[i] %= mod;
		cin >> a[i];
		cnt0 += (a[i] == 0);
	}
	for (int i = 0; i < n; i++) {
		cnt1 += (s[i] ^ 48);
	}
	if (min(n - cnt0, cnt1) < m) {
		cout << 0;
		return 0;
	}
	if (cnt1 == n) {
		if (!cnt0) {
			cout << jie[n];
			return 0;
		} else if (n >= 20) {
			cout << 0;
			return 0;
		}
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}