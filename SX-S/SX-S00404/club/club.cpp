#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);++i)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);++i)
typedef long long ll;
#define fi first
#define se second
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
const int N = 1e5+5, M = 305;
ll f[M][M][M];
int n;

struct no {
	int x, y, z, p;
	void read() {
		cin >> x >> y >> z;
	}
} s[N];

void MAIN() {
	me(f, 0);
	cin >> n;
	bool fl = 0, flg = 0;
	For(i, 1, n)s[i].read();
	For(i, 1, n) {
		if (s[i].y || s[i].z)
			fl = 1;
		if (s[i].z)
			flg = 1;
	}
	if (!fl) {
		sort(s + 1, s + n + 1,
		[](no x, no y) {
			return x.x > y.x;
		});
		ll ans = 0;
		For(i, 1, n / 2) {
			ans += s[i].x;
		}
		cout << ans << endl;
		return;
	}
	if (!flg) {
		sort(s + 1, s + n + 1,
		[](no x, no y) {
			return x.x - x.y > y.x - y.y;
		});
		ll ans = 0;
		For(i, 1, n / 2) {
			ans += s[i].x;
		}
		For(i, n / 2 + 1, n) {
			ans += s[i].y;
		}
		cout << ans << endl;
		return;
	}
	For(i, 1, n) {
		For(a, 0, min(i, n / 2)) {
			For(b, 0, min(i - a, n / 2)) {
				int c = i - a - b;
				if (c > n / 2)
					continue;
				if (a)
					f[i][a][b] = max(f[i][a][b], f[i - 1][a - 1][b] + s[i].x);
				if (b)
					f[i][a][b] = max(f[i][a][b], f[i - 1][a][b - 1] + s[i].y);
				if (c)
					f[i][a][b] = max(f[i][a][b], f[i - 1][a][b] + s[i].z);
			}
		}
	}
	ll ans = 0;
	For(a, 0, n / 2) {
		For(b, 0, min(n - a, n / 2)) {
			if (n - a - b <= n / 2)
				ans = max(ans, f[n][a][b]);
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		MAIN();
	}
	return 0;
}
