#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 18, mod = 998244353;

ll n, m;
string s;
ll a[N], dp[(1 << N) + 5][N + 5];
bool b[N + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) b[i] = s[i - 1] - '0';
	if (n <= 18) {
		for (int i = 0; i < n; i++) {
			if (a[i + 1]) dp[1 << i][b[1]] = 1;
			else dp[1 << i][0] = 1;
		}
		for (int i = 0; i < (1 << n); i++) {
			int t = __builtin_popcount(i);
			for (int j = 0; j < n; j++) {
				if (!(i & (1 << j))) {
					for (int k = 0; k <= n; k++) {
						if (t - k >= a[j + 1] || b[t + 1] == 0) dp[i + (1 << j)][k] += dp[i][k];
						else dp[i + (1 << j)][k + 1] += dp[i][k];
					}
				}
			}
		}
		int ans = 0;
		for (int i = m; i <= n; i++) ans = (ans + dp[(1 << n) - 1][i]) % mod;
		cout << ans;
	}
	else if (m == n){
		bool f = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] == 0 || a[i] == 0) f = 1;
		}
		if (f) cout << 0;
		else {
			int ans = 1;
			for (int i = 1; i <= n; i++) ans = ans * i % mod;
			cout << ans;
		}
	}
	
	return 0;
}
