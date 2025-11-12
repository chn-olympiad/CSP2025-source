#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;

struct up {
	int a, b, c, ma, mb, mc;
} x[100005];

bool cmp1(up o, up p) {
	if (o.mc == p.mc)
		return o.ma > p.ma;
	return o.mc > p.mc;
}



signed main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		memset(x, 0, sizeof x);
		cin >> n;
		int a = 0, b = 0, c = 0, lim = n / 2, ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i].a >> x[i].b >> x[i].c;
			int f[4];
			f[1] = x[i].a, f[2] = x[i].b, f[3] = x[i].c;
			sort(f + 1, f + 1 + 3);
			x[i].ma = f[3], x[i].mb = f[2], x[i].mc = f[3] - f[2];
		}
		//ma biggist  mb second   mc  ma-mb
		sort(x + 1, x + n + 1, cmp1);
		for (int i = 1; i <= n; i++) {
			if (a != lim && b != lim && c != lim) {
				ans += x[i].ma;

//				cout << x[i].ma << " ";

				if (x[i].ma == x[i].a)
					a++;
				else if (x[i].ma == x[i].b)
					b++;
				else
					c++;
			} else {
				if ((a == lim && x[i].ma == x[i].a) || (b == lim && x[i].ma == x[i].b) || (c == lim && x[i].ma == x[i].c))
					ans += x[i].mb;
				else
					ans += x[i].ma;

//				cout << x[i].mb << " ";

			}
		}
		cout << ans << "\n";

//		for (int i = 1; i <= n; i++) {
//			cout << x[i].ma << " " << x[i].mb << " " << x[i].mc << "\n";
//		}

	}
	return 0;
}