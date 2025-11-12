#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define sz size
#define fi first
#define se second
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 505;
const int mod = 998244353;

int n, m, a[N], c[N], f[(1 << 18) + 5][20];
char s[N];

void solve1() {
	f[0][0] = 1;
	for (int s = 0; s < 1 << n; s++) {
		int p = __builtin_popcount(s);
		for (int i = 1; i <= n; i++)
			if (!(s >> (i - 1) & 1)) {
				for (int j = 0; j <= n; j++) {
					if (a[p + 1] == 1 || c[i] <= p - j) f[s ^ (1 << i - 1)][j] = (f[s ^ (1 << i - 1)][j] + f[s][j]) % mod;
					else f[s ^ (1 << i - 1)][j + 1] = (f[s ^ (1 << i - 1)][j + 1] + f[s][j]) % mod;
				}
			}
	}
	int ans = 0;
	for (int i = m; i <= n; i++) ans = (ans + f[(1 << n) - 1][i]) % mod;
	cout << ans << '\n';
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> s + 1;
	for (int i = 1; i <= n; i++) a[i] = !(s[i] - '0');
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 18) solve1();
	return 0;
}