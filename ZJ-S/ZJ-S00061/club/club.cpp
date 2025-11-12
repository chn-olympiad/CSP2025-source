#include <bits/stdc++.h>
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i ++)
#define PER(i, a, b) for (int i = a; i >= b; i --)
using namespace std;
const int N = 1e5 + 10;
int n, a[N][5], cnt[5], id[N], mn[N], tj[N], ans, tot;
inline void uniextis() {
	cin >> n;
	ans = tot = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	REP(i, 1, n) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			cnt[1] ++;
			id[i] = 1;
			ans += a[i][1];
			mn[i] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
		}
		else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			cnt[2] ++;
			id[i] = 2;
			ans += a[i][2];
			mn[i] = min(a[i][2] - a[i][1], a[i][2] - a[i][3]);
		}
		else {
			cnt[3] ++;
			id[i] = 3;
			ans += a[i][3];
			mn[i] = min(a[i][3] - a[i][2], a[i][3] - a[i][1]);
		}
	}
	int x;
	REP(i, 1, 3) if (cnt[i] > n / 2) x = i;
	REP(i, 1, n) {
		if (id[i] == x) {
			tj[++ tot] = mn[i];
		}
	}
	sort(tj + 1, tj + 1 + tot);
	REP(i, 1, cnt[x] - n / 2) ans -= tj[i];
	cout << ans << '\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T --) uniextis();
	return 0;
}
/*

*/

