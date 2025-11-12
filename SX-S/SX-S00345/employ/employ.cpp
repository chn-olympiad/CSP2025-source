#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10, mod = 998244353;
ll  n, m, ans = 1, cnt = 1, c[N];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	ll no = n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0) {
			no--;
		}
	}
	bool f = 0;
	for (int i = 0; i < n; i++) {
		if ((s[i] - '0') == 1) {
			f = 1;
		}
	}
	if (m == 1 && f == 1) {
		cout << n;
	} else {
		for (int i = no; i >= no - m + 1; i--) {
			ans *= i;
			ans /= (no - i + 1);
		}
		for (int i = 2; i <= m; i++) {
			ans *= i;
		}
		cout << ans % mod;
	}
	return 0;
}
