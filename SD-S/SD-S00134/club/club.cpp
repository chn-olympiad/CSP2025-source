#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define maxn 1000007
const int INF = 1e9 + 7;
int t, n, a[maxn][4];
int vis[204][204][204], ans;
int x[maxn], y[maxn], z[maxn];
int la, lb, lc;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			x[i] = y[i] = z[i] = 0;
		}
		ans = la = lb = lc = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				ans += a[i][1];
				x[++ la] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
			} else if (a[i][1] <= a[i][2] && a[i][2] >= a[i][3]) {
				ans += a[i][2];
				y[++ lb] = min(a[i][2] - a[i][1], a[i][2] - a[i][3]);
			} else {
				ans += a[i][3];
				z[++ lc] = min(a[i][3] - a[i][2], a[i][3] - a[i][1]);
			}
		}
		if (la > n / 2) {
			sort(x + 1, x + 1 + la);
			for (int i = 1; i <= la - n / 2; i ++) {
				ans -= x[i];
			}
		} else if (lb > n / 2) {
			sort(y + 1, y + 1 + lb);
			for (int i = 1; i <= lb - n / 2; i ++) {
				ans -= y[i];
			}
		} else if (lc > n / 2) {
			sort(z + 1, z + 1 + lc);
			for (int i = 1; i <= lc - n / 2; i ++) {
				ans -= z[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

