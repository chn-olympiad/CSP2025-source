#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 5e2 + 7, M = 1e3;
const int mod = 998244353;
int n, m, a[N], num;
string s, t;
void IOS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	return ;
}
void file() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	return ;
}
void __init() {
	file(), IOS();
	return ;
}
void solve() {
	cin >> n >> m >> s;
	int len = s.size();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 0) {
			++num;
		}
	}
	sort (a + 1, a + n + 1);
	for (int i = 0; i < len; ++i) {
		t = t + "1";
	}
	if (s == t) {
		LL ans = 1;
		while (num) {
			ans *= num;
			ans %= mod;
			--num;
		}
		cout << ans % mod << '\n';
		return ;
	}
	cout << "0\n";
	return ;
}
int main(void) {
	__init();
	LL _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}