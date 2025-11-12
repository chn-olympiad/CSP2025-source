#include <bits/stdc++.h>
#define debug cout << "\n------------debug------------\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef __int128 LLL;
typedef pair <int, int> PII;
typedef pair <LL, int> PLI;
typedef pair <int, LL> PIL;
typedef pair <LL, LL> PLL;

inline LL read() {
	LL x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

inline void write(LL x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 205;
const int MAXN_ = 1e5 + 5;
const int MAXA = 2e4 + 5;
LL N, a[MAXN_][4];
LL dp[MAXN][MAXN >> 1][MAXN >> 1];

inline LL dfs(int i, int j, int k, int x) {
	if (!dp[i][j][k] && x < dp[i][j][k]) {
		return dp[i][j][k];
	}
	if (i > N)
		return 0;
	if (j > (N >> 1))
		return 0;
	if (k > (N >> 1))
		return 0;
	if (i - j - k > (N >> 1))
		return 0;
	LL res = x; 
	res = max(res, dfs(i + 1, j + 1, k, x + a[i + 1][1]));
	res = max(res, dfs(i + 1, j, k + 1, x + a[i + 1][2]));
	res = max(res, dfs(i + 1, j, k, x + a[i + 1][3]));
	dp[i][j][k] = res;
//	cout << i << ' ' << j << ' ' << k << ':' << dp[i][j][k] << '\n';
	return res;
}

inline void solve() {
//	debug;
	N = read();
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	bool flagA = 1;
	for (int i = 1; i <= N; ++i) {
		a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
		if (a[i][2] != 0 || a[i][3] != 0) {
			flagA = 0;
		}
	}
	if (N <= 10) {
		write(dfs(0, 0, 0, 0)), putchar('\n');
		return;
	}
	if (flagA) {
		vector <LL> _a(N);
		for (int i = 1; i <= N; ++i) {
			_a[i - 1] = a[i][1];
		}
		sort(_a.begin(), _a.end(), greater <LL> ());
		LL ans = 0;
		for (int i = 0; i <= (N >> 1) - 1; ++i) {
			ans += _a[i];
		}
		write(ans), putchar('\n');
		return;
	}
	if (N <= 200) {
		dp[1][0][0] = a[1][3], dp[1][1][0] = a[1][1], dp[1][0][1] = a[1][2];
		for (int i = 2; i <= N; ++i) {
			for (int j = 0; j <= min((LL)i, (N >> 1)); ++j) {
				for (int k = 0; k <= min((LL)i - j, (N >> 1)); ++k) {
					if (k < i - j - (N >> 1))
						continue;
					dp[i][j][k] = max({dp[i][j][k], (i > 1 ? dp[i - 1][j][k] + a[i][3] : a[i][3]), (i > 1 ? dp[i - 1][j - 1][k] + a[i][1] : a[i][1]), (i > 1 ? dp[i - 1][j][k - 1] + a[i][2] : a[i][2])});
				}
			}
		}
//		debug;
//		for (int i = 0; i <= N; ++i) {
//			for (int j = 0; j <= N; ++j) {
//				for (int k = 0; k <= N; ++k) {
//					cout << i << ' ' << j << ' ' << k << ':' << dp[i][j][k] << '\n';
//				}
//			}
//		}
		LL ans = 0;
		for (int j = 1; j <= (N >> 1); ++j) {
			for (int k = 1; k <= (N >> 1); ++k) {
				ans = max(ans, dp[N][j][k]);
			}
		}
		write(ans), putchar('\n');
		return;
	}
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T--) {
		solve();
	}
	return 0;
}

