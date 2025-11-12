#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c;
	int maxid, id;
} a[100005];
int n;
int v[100005];
long long ans;

inline bool cmpa(node x, node y) {
	if (x.maxid == y.maxid)
		return x.a > y.a;
	else
		return x.maxid < y.maxid;
}

inline bool cmpc(node x, node y) {
	if (x.maxid == y.maxid)
		return x.c > y.c;
	else
		return x.maxid > y.maxid;
}

inline bool cmpb(node x, node y) {
	return x.b > y.b;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> n;
		int lim = n / 2;
		for (int i = 1; i <= n; i++) {
			v[i] = 0;
			a[i].id = i;
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].a > a[i].c && a[i].a > a[i].b) {
				a[i].maxid = 1;
			} else if (a[i].c > a[i].a && a[i].c > a[i].b) {
				a[i].maxid = 3;
			} else if (a[i].b > a[i].a && a[i].b > a[i].a) {
				a[i].maxid = 2;
			}
			if (a[i].c == 0 && a[i].b == 0) {
				a[i].maxid = -2;
			}
			if (a[i].a == 0 && a[i].b == 0) {
				a[i].maxid = 4;
			}
		}
		int cnt = 0;
		sort(a + 1, a + 1 + n, cmpa);
		for (int i = 1; i <= n; i++) {
			if (cnt >= lim)
				break;
			if (a[i].a == 0)
				continue;
			if (!v[a[i].id] && (a[i].maxid == 1 || a[i].maxid == -2)) {
				ans += a[i].a;
				v[a[i].id] = 1;
				cnt++;
			}
		}
		cnt = 0;
		sort(a + 1, a + 1 + n, cmpc);
		for (int i = 1; i <= n; i++) {
			if (cnt >= lim)
				break;
			if (a[i].c == 0)
				continue;
			if (!v[a[i].id] && (a[i].maxid == 3 || a[i].maxid == 4)) {
				ans += a[i].c;
				v[a[i].id] = 1;
				cnt++;
			}
		}
		cnt = 0;
		sort(a + 1, a + 1 + n, cmpb);
		for (int i = 1; i <= n; i++) {
			if (cnt >= lim)
				break;
			if (!v[a[i].id]) {
				ans += a[i].b;
				v[a[i].id] = 1;
				cnt++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
