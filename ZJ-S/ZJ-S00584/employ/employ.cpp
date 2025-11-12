#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); i ++)
#define DEP(i, r, l) for (int i = (r); i >= (l); i ++)
#define CUP(i, l, r) for (int i = (l); i < (r); i ++)
#define fi first
#define se second
#define mems(a, v) memset((a), (v), sizeof(a))
#define memc(a, b) memcpy((a), (b), sizeof(b))
#define pb emplace_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define ppc __builtin_popcount
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 505, mod = 998244353;
	LL n, m, x, rs, c[N], fc[N], f[N][N], g[N][N]; char s[N];
	void add(LL &x, LL y) { x = (x + y) % mod, (x < 0) && (x += mod); }
	int main() {
		cin >> n >> m;
		REP(i, 1, n) cin >> s[i];
		REP(i, 1, n) cin >> x, c[x] ++;
		REP(i, 1, n) c[i] += c[i - 1];
		f[0][0] = 1;
		REP(i, 1, n) {
			REP(j, 0, i) REP(k, 0, i) {
				if (!f[j][k]) continue;
				if (s[i] == '1') {
					add(g[j + 1][k + 1], f[j][k] * (c[j] - k));
					add(g[j][k], f[j][k]);
					add(g[j][k + 1], -f[j][k] * (c[j] - k));
				} else {
					add(g[j + 1][k], f[j][k]);
				}
			}
			memc(f, g), mems(g, 0);
		}
		REP(i, 0, n) fc[i] = (i ? fc[i - 1] * i % mod : 1);
		REP(i, 0, n - m) REP(j, 0, n)
			add(rs, f[i][j] * fc[n - j]);
		cout << rs << '\n';
		return 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}