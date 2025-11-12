#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define pr pair<int, int>
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
#define iosfst ios :: sync_with_stdio(false);cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 200, mod = 998244353;
int n, a[5005], ans, sum, f[2][N + 1][N * N + 1], g[2][N + 1][N * N + 1], k[5005];
unordered_map<int, int> mp;
int hsh(int cnt) {
	int pw = 233, h = 0;
	rep (i, 1, cnt) h = h * pw % mod + k[i] * k[i] * k[i] % mod, h %= mod;
	return h;
}
void dfs(int p, int cnt, int sum, int mx) {
	if (cnt >= 3) {
		int kk = hsh(cnt);
		if (2 * mx < sum && !mp.count(kk)) ans++, mp[kk] = 1;
	}
	if (p == n + 1) return;
	dfs(p + 1, cnt, sum, mx);
	k[cnt + 1] = p;
	dfs(p + 1, cnt + 1, sum + a[p], a[p]);
	return;
}
signed main() {
	iosfst;
	File("polygon");
	cin >> n;
	rep (i, 1, n) cin >> a[i], sum += a[i];
	sort(a + 1, a + n + 1);
	if (n <= 10) {
		dfs(1, 0, 0, 0);
		cout << ans;
	}
	else {
		memset(f[2 & 1], -1, sizeof f[2 & 1]);
		f[2 & 1][0][0] = f[2 & 1][1][a[1]] = f[2 & 1][1][a[2]] = f[2 & 1][2][a[1] + a[2]] = 0;
		g[2 & 1][0][0]++;
		g[2 & 1][1][a[1]]++;
		g[2 & 1][1][a[2]]++;
		g[2 & 1][2][a[1] + a[2]]++;
		rep (i, 3, n) {
			memset(f[i & 1], -1, sizeof f[i & 1]);
			memset(g[i & 1], 0, sizeof g[i & 1]);
			rep (j, 0, i) {
				if (j == 0) {
					f[i & 1][0][0] = 0;
					g[i & 1][0][0]++;
					continue;
				}
				rep (k, a[i], sum) if (f[i & 1 ^ 1][j - 1][k - a[i]] != -1) f[i & 1][j][k] = 0, g[i & 1][j][k] += g[i & 1 ^ 1][j - 1][k - a[i]];
				rep (k, 0, sum) if (f[i & 1 ^ 1][j][k] != -1) {
					if (f[i & 1 ^ 1][j][k] == 0) f[i & 1][j][k] = f[i & 1 ^ 1][j][k], g[i & 1][j][k] += g[i & 1 ^ 1][j][k];
					else f[i & 1][j][k] = f[i & 1 ^ 1][j][k], g[i & 1][j][k] = g[i & 1 ^ 1][j][k];
				}
				if (j > 2) rep (k, a[i], sum) if (a[i] * 2 < k && f[i & 1 ^ 1][j - 1][k - a[i]] != -1) {
					if (f[i & 1 ^ 1][j - 1][k - a[i]] == 0) (f[i & 1][j][k] += g[i & 1 ^ 1][j - 1][k - a[i]]) %= mod;//g[i & 1 ^ 1][j - 1][k - a[i]];
					else f[i & 1][j][k] = (f[i & 1][j][k] + f[i & 1 ^ 1][j - 1][k - a[i]] + g[i & 1 ^ 1][j - 1][k - a[i]] - 1) % mod;
				}
			}
	//		rep (j, 0, i) {
	//			rep (k, 0, sum) cout << f[i & 1][j][k] << ' ';
	//			cout << '\n';
	//		}
	//		cout << "\n\n\n\n";
	//		rep (j, 0, i) {
	//			rep (k, 0, sum) cout << g[i & 1][j][k] << ' ';
	//			cout << '\n';
	//		}
		}
		rep (j, 3, n) rep (i, 0, sum) if (f[n & 1][j][i] != -1) (ans += f[n & 1][j][i]) %= mod;
		cout << ans;
	}
//	cout << (&b2 - &b1) / 1024.0 / 1024.0;
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
