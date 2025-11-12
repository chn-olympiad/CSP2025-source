// 吴昱胤 SN-S00113 西安铁一中国际合作学校
// By 0x0F
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long
const int mod = 998244353;
int n, m;
ll fac[510];
int a[510], c[510];
int dp[510][510][510];
string s;
void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	s = ' ' + s;
	bool flg = 1;
	for (int i = 1; i <= n; i++) if (s[i] == '0') flg = 0;
	if (flg == 1) {
		
		return;
	}
	for (int i = 1; i <= n; i++) a[i] = i;
	int ans = 0;
	do {
		int fail = 0, suc = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0' || fail >= c[a[i]]) fail++;
			else suc++;
		}
		if (suc >= m) ans = (ans +1) % mod;
	} while (next_permutation(a + 1, a + n + 1));
	cout << ans << endl;
}
int main() {
	ios :: sync_with_stdio(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	solve();
	return 0;
}

