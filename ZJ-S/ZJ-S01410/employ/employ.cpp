#include <bits/stdc++.h> 
using namespace std;

const int maxn = 2e6 + 5;
typedef long long ll;

int a[maxn], c[maxn];

int n, m;
string s;

ll dp[1 << 18][20]; // dp[i][j]: use man state = i,manba out man = j
int day[maxn]; // guoqu le jitian
const ll mod = 998244353;
void solve1() {
	for (int i = 0; i < n; i++) {
		if (a[0] == 0 || c[i] == 0) dp[1 << i][1] = 1; // manba out
		else dp[1 << i][0] = 1; // manba in
	}
	
	for (int i = 0; i < (1 << n); i++) {
		int temp = i;
		while (temp) day[i] += temp % 2, temp /= 2;
	}
	
	for (int x = 1; x < (1 << n); x++) {
		// next man: i
		int d = day[x];
		for (int i = 0; i < n; i++) {
			if (x & (1 << i)) continue;
			// now out manba number: j
			for (int j = 0; j <= d; j++) {
				if (a[d] == 0 || j >= c[i]) (dp[x | (1 << i)][j + 1] += dp[x][j]) %= mod;
				else (dp[x | (1 << i)][j] += dp[x][j]) %= mod;
			}
			
		}
//		cout << x << " " << dp[x][0] << ' ' << dp[x][1] << ' ' << dp[x][2] << ' ' << dp[x][3] << endl;
	}
	
	ll ans = 0;
	for (int i = 0; n - i >= m; i++) {
		ans += dp[(1 << n) - 1][i];
		ans %= mod;
	}
	cout << ans << endl;
	
}
int pre[maxn];
ll fac[maxn];
void solve2() {
	int cnt = 0;
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) continue ;
		if (pre[i] - cnt <= 0) ans = 0;
		else ans = ans * (pre[i - 1] - cnt) % mod;
//		cout << pre[i] - cnt<< " ";
		cnt++;
	}
//	cout << fac[n - cnt] << endl;
	ans = ans * fac[n - cnt] % mod;
	cout << ((fac[n] - ans) % mod + mod ) % mod << endl;
}

void solve3() {
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0 || a[i] == 0) {
			cout << 0 << endl;
			return ;
		}
	}
	cout << fac[n] << endl;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) a[i] = s[i] - '0';
	for (int i = 0; i < n; i++) cin >> c[i];
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod ;
	if (n <= 18) {
		solve1();
		return 0;	
	}
	
	for (int i = n; i >= 1; i--) a[i] = a[i - 1], c[i] = c[i - 1];
	for (int i = 1; i <= n; i++) pre[c[i]]++;
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + pre[i];
	
	if (m == 1) solve2();
	else if(m == n) solve3();
	
}