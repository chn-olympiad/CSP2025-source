#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
const int mod = 998244353;
int n, m, a[N];
char p[N];
namespace Sol1 {
	int c[N], ans;
	inline int check() {
		int cnt = 0;
		for(int i = 1; i <= n; i ++) {
			if(p[i] == '0') {
				cnt ++;
				continue;
			}
			if(a[c[i]] <= cnt) cnt ++;
		}
		cout << n - cnt << ' ';
		return n - cnt >= m;
	}
	inline void dfs(int u) {
		if(u == n + 1) {
			ans += check();
			return;
		}
		for(int i = 1; i <= n; i ++) {
			if(!c[i]) {
				c[i] = u;
				dfs(u + 1);
				c[i] = 0;
			}
		}
	}
	inline void solve() {
		dfs(1);
		cout << ans;
	}
}
namespace Sol2 {
	int dp[N];
	inline void solve() {
		for(int i = 1; i <= n; i ++)if(p[i] == '0' || a[i] == 0) {
				cout << 0;
				return;
			}
		int ans = 1;
		for(int i = 1; i <= n; i ++)ans = ans * i % mod;
		cout << ans;
	}
}
namespace Sol3 {
	int dp[N][N], cnt[N];
	inline void solve() {
		for(int i = 1; i <= n; i ++)cnt[a[i]] ++;
		for(int i = 1;i <= n;i ++)cnt[i] += cnt[i - 1];
		int ans = 0;
		dp[0][0] = 1;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j <= i; j ++) {
				dp[i][j] %= mod;
				if(j < cnt[j])dp[i + 1][j + 1] += dp[i][j] * (cnt[j] - j) % mod;
//				if(n - i - (cnt[j] - j) <= 0)cout << i << ' '<< j << '\n';
				if(n - i - (cnt[j] - j) > 0)dp[i + 1][j] += dp[i][j] * (n - i - (cnt[j] - j)) % mod;
			}
		}
		for(int i = 0; i <= n; i ++){
			if(n - i < m)break;
			ans += dp[n][i];
			ans %= mod;
		}
		cout << ans; 
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int flag = 1;
	for(int i = 1; i <= n; i ++)cin >> p[i], flag &= p[i] == '1';
	for(int i = 1; i <= n; i ++)cin >> a[i];
	if(n <= 10) {
		Sol1 :: solve();
		return 0;
	}
	if(m == n) {
		Sol2 :: solve();
		return 0;
	} else cout << 0;
	return 0;
}
