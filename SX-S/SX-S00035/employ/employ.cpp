#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))
using namespace std;
const int N = 505, mod = 998244353;
int n, m, s[N], c[N], fac[N], infac[N];
string str;

int ksm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			res = 1ll * res * a % mod;
		b >>= 1, a = 1ll * a * a % mod;
	}
	return res;
}

namespace SubA {
	int dp[N][N];
	void add(int &a, int b) {
		a += b;
		if (a >= mod)
			a -= mod;
	}
	void solve() {
		sort(c + 1, c + n + 1);
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				int x = min(i, c[i] + j);
				add(dp[i][j + 1], 1ll * dp[i - 1][j]*x % mod);
				add(dp[i][j], 1ll * dp[i - 1][j] * (i - x) % mod);
			}
		}
		int ans = 0;
		for (int j = m; j <= n; j++)
			add(ans, dp[n][j]);
		cout << ans << endl;
	}
}

namespace SubM1 {
	int cnt[N], sum, ans = 1, qwq = 0;
	void solve() {
		for (int i = 1; i <= n; i++)
			if (c[i] <= n)
				cnt[c[i]]++;
		for (int i = 1; i <= n; i++) {
			sum += cnt[i - 1];
			if (s[i] == 1)
				ans = 1ll * ans * sum % mod, sum--;
			else
				qwq++;
		}
		ans = 1ll * ans * fac[qwq] % mod;
		cout << (fac[n] - ans + mod) % mod << endl;
	}
}

namespace Sub0 {
	const int W = 1 << 18, K = 20;
	int dp[W][K], ppc[W], ans;
	void add(int &a, int b) {
		a += b;
		if (a >= mod)
			a -= mod;
	}
	void solve() {
		int V = 1 << n;
		for (int S = 0; S < V; S++)
			for (int i = 0; i < n; i++)
				if (S & (1 << i))
					ppc[S]++;
		dp[0][0] = 1;
		for (int S = 0; S < V - 1; S++) {
			for (int i = 0; i <= ppc[S]; i++) {
				for (int j = 0; j < n; j++) {
					if (S & (1 << j))
						continue;
					if (c[j + 1] <= ppc[S] - i || s[ppc[S] + 1] == 0)
						add(dp[S | (1 << j)][i], dp[S][i]);
					else
						add(dp[S | (1 << j)][i + 1], dp[S][i]);
				}
			}
		}
		for (int i = m; i <= n; i++)
			add(ans, dp[V - 1][i]);
		cout << ans << endl;
	}
}

signed main() {
	File("employ");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> str;
	bool flag = 1;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		s[i] = (str[i - 1] == '1'), flag &= s[i];
	fac[0] = infac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	infac[n] = ksm(fac[n], mod - 2);
	for (int i = n - 1; i >= 1; i--)
		infac[i] = 1ll * infac[i + 1] * (i + 1) % mod;
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			if (s[i] == 0 || c[i] == 0) {
				cout << 0 << endl;
				return 0;
			}
		}
		cout << fac[n] << endl;
		return 0;
	}
	if (m == 1) {
		SubM1::solve();
		return 0;
	}
	if (flag) {
		SubA::solve();
		return 0;
	}
	if (n <= 18) {
		Sub0::solve();
		return 0;
	}
	return 0;
}
/*
fc /W test.out test.ans
*/
