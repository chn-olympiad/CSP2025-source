#include <bits/stdc++.h>
#define i32 int
#define i64 long long
#define For(i, l, r) for (i32 i = (l); i <= (r); i++)
using namespace std;

const i32 N = 1e5 + 5;
i32 a[N][3], op[N];
i32 b[N], c[N];
inline void ___() {
	i32 n; cin >> n;
	i32 cnt[3] = {  };
	i64 ans = 0;
	For (i, 1, n) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		i32 ma = max({ a[i][0], a[i][1], a[i][2] });
		i32 se = -1;
		if (a[i][0] == ma) se = max(a[i][1], a[i][2]), cnt[0]++, op[i] = 0;
		else if (a[i][1] == ma) se = max(a[i][0], a[i][2]), cnt[1]++, op[i] = 1;
		else if (a[i][2] == ma) se = max(a[i][1], a[i][0]), cnt[2]++, op[i] = 2;
		b[i] = ma, c[i] = se;
		ans += ma;
	}
	if (cnt[0] > n / 2 || cnt[1] > n / 2 || cnt[2] > n / 2) {
		i32 tmp = -1;
		if (cnt[0] > n / 2) tmp = 0;
		if (cnt[1] > n / 2) tmp = 1;
		if (cnt[2] > n / 2) tmp = 2;
		priority_queue < i32 > g;
		For (i, 1, n) {
			if (op[i] == tmp) {
				g.push(c[i] - b[i]);
			}
		}
		while (cnt[tmp] > n / 2) {
			ans += g.top();
			g.pop(); cnt[tmp]--;
		}
	}
	cout << ans << '\n';
}



signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	i32 T = 1; cin >> T;
	while (T--) ___();
}