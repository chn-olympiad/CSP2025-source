#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); i ++)
#define DEP(i, r, l) for (int i = (r); i >= (l); i ++)
#define CUP(i, l, r) for (int i = (l); i < (r); i ++)
#define fi first
#define se second
#define mems(a, v) memset((a), (v), sizeof(a))
#define memc(a, b) memset((a), (b), sizeof(b))
#define pb emplace_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define ppc __builtin_popcount
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 1e6 + 5;
	LL n, rs, a[N][3], b[N], c[3];
	int main() {
		cin >> n, rs = 0, mems(c, 0);
		REP(i, 1, n) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int x = max_element(a[i], a[i] + 3) - a[i];
			c[x] ++, rs += a[i][x];
		}
		if (max({c[0], c[1], c[2]}) <= n / 2) {
			cout << rs << '\n';
			return 0;
		}
		rs = 0;
		REP(x, 0, 2) {
			LL w = 0, y = (x + 1) % 3, z = (y + 1) % 3;
			REP(i, 1, n) {
				LL t = max(a[i][y], a[i][z]);
				w += t, b[i] = a[i][x] - t;
			}
			sort(b + 1, b + 1 + n);
			REP(i, n / 2 + 1, n) w += b[i];
			rs = max(rs, w); 
		}
		cout << rs << '\n';
		return 0;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1; cin >> T;
	while (T --) Milkcat::main();
	return 0;
}