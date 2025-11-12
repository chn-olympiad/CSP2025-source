#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define int long long

struct node {
	int a, b, c;
};
node v[N], ca[N], cb[N], cc[N], now;

bool cmp1(node x, node y) {
	return x.a - max(x.c, x.b) < y.a - max(y.c, y.b);
}

bool cmp2(node x, node y) {
	return x.b - max(x.a, x.c) < y.b - max(y.a, y.c);
}

bool cmp3(node x, node y) {
	return x.c - max(x.a, x.b) < y.c - max(y.a, y.b);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n, a = 0, b = 0, c = 0, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> v[i].a >> v[i].b >> v[i].c;
			now.a = v[i].a;
			now.b = v[i].b;
			now.c = v[i].c;
			if (v[i].a >= max(v[i].b, v[i].c)) {
				ans += v[i].a;
				a++;
				ca[a] = now;
			} else if (v[i].b >= max(v[i].a, v[i].c)) {
				ans += v[i].b;
				b++;
				cb[b] = now;
			} else {
				ans += v[i].c;
				c++;
				cc[c] = now;
			}
		}
		//cout << ans << endl;
		if (a > n / 2) {
			//	cout << 1 << endl;
			sort(ca + 1, ca + 1 + a, cmp1);
			for (int i = 1; i <= a - n / 2; i++) {

				//	cout << "//" << ca[i].a << " " << ca[i].b << " " << ca[i].c << endl;
				ans = ans - ca[i].a + max(ca[i].b, ca[i].c);
				//		cout << ans << endl;
			}
		}
		if (b > n / 2) {
			//	cout << 2 << endl;
			sort(cb + 1, cb + b + 1, cmp2);
			for (int i = 1; i <= b - n / 2; i++) {
				//	cout << "//" << cb[i].a << " " << cb[i].b << " " << cb[i].c << endl;
				ans = ans - cb[i].b + max(cb[i].a, cb[i].c);
				//	cout << ans << endl;
			}
		}
		if (c > n / 2) {
			//	cout << 3 << " " << c - n / 2 << endl;
			sort(cc + 1, cc + c + 1, cmp3);
			//	for (int i = 1; i <= c; i++) {
			//		cout << cc[i].c - max(cc[i].a, cc[i].b) << endl;
			//	}
			for (int i = 1; i <= c - n / 2; i++) {
				//	cout << "//" << cc[i].a << " " << cc[i].b << " " << cc[i].c << endl;
				ans = ans - cc[i].c + max(cc[i].a, cc[i].b);
				//	cout << ans << endl;
			}
		}
		cout << ans << endl;

	}
	return 0;
}