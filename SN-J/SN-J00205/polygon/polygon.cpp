#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
const int mod = 998244353;
int a[N], b[N], dp[N], sum, n, cnt = 1, l, ans;
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 10000; j > 10000 - a[i]; j--) {
			dp[j + a[i]] += dp[j];
			dp[j + a[i]] %= mod;
		}
		sort(a + 1, a + n + 1);
	}
	for (int i = 10000; i > 10000 - a[i]; i --) {
		cout << dp[i] << ' ';
	}
	return 0;
}

