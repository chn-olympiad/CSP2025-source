#include <bits/stdc++.h>
using namespace std;

struct hh {
	int a, b, c;
	int manyi;
	int vis, dis;
	int k;
} v[100005];

bool cmp(hh f, hh g) {
	return f.vis > g.vis;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, ans;
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		int x = n / 2;
		int a2 = 0, b2 = 0, c2 = 0, m;
		for (int i = 1; i <= n; i++) {
			cin >> v[i].a >> v[i].b >> v[i].c;
			if (v[i].a >= v[i].b && v[i].a >= v[i].c) {
				a2++;
				ans += v[i].a;
				v[i].vis = v[i].a - max(v[i].b, v[i].c);
				v[i].dis = v[i].a - min(v[i].b, v[i].c);
//				v[i].vis = v[i].a - v[i].b;
//				v[i].dis = v[i].a - v[i].c;
				v[i].manyi = 1;
			} else if (v[i].b > v[i].a && v[i].b > v[i].c) {
				b2++;
				ans += v[i].b;
				v[i].vis = v[i].b - max(v[i].a, v[i].c);
				v[i].dis = v[i].b - min(v[i].a, v[i].c);
//				v[i].vis = v[i].b - v[i].a;
//				v[i].dis = v[i].b - v[i].c;
				v[i].manyi = 2;
			} else {
				c2++;
				ans += v[i].c;
				v[i].vis = v[i].c - max(v[i].b, v[i].a);
				v[i].dis = v[i].c - min(v[i].b, v[i].a);
//				v[i].vis = v[i].c - v[i].b;
//				v[i].dis = v[i].c - v[i].a;
				v[i].manyi = 3;
			}
		}
		sort(v + 1, v + n + 1, cmp);
		if (a2 > x) {
			for (int i = 1; i <= a2 - x; i++) {
				ans += v[i].vis;
			}
		}
		if (b2 > x) {
			for (int i = 1; i <= b2 - x; i++) {
				ans += v[i].vis;
			}
		}
		if (c2 > x) {
			for (int i = 1; i <= c2 - x; i++) {
				ans += v[i].vis;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}