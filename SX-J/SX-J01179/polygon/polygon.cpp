#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[6000], ans = 0;
const int mod = 998244353;
int n;

/*
RP++
CCF I ll never call u coin collection federation so plz spare me and give me some pts
plz
All For My True Love
particularly bless me in the afternoon plz
orecic orz
Tgiwz orz
I reaaaaaally need a prize for my further development so please give me it
I'll never use coin collection federation and cash cycle federation
Instead i'll use comfortable competitors federation
so plz give me it
RP++
*/
void dfs(int dep, int maxn, int sum, int put) {
	if (dep > n) {
		if (put >= 3)
			if (sum > maxn * 2) {
				ans++;
				ans %= mod;
			}
	} else {
		dfs(dep + 1, max(maxn, a[dep]), sum + a[dep], put + 1);
		dfs(dep + 1, maxn, sum, put);
	}
}
int dp[5000];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	int maximum = 0;
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
		maximum = max(maximum, a[x]);
	}
//	if (maximum == 1) {
//		dp[2] = 1;
//		for (int get_out = 1; get_out <= n; get_out++) {
//			for (int x = get_out; x <= n; x++) {
//				dp[x] = dp[x - 1] * (x - 2) % mod;
//				dp[x] %= mod;
//			}
//			if (get_out >= 3) {
//				ans += dp[n];
//				ans %= mod;
//			}
//		}
//		cout << ans;
//		return 0;
//	}
	dfs(1, -1, 0, 0);
	cout << ans;
	return 0;
}
