#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;

struct myd {
	int a, b, c, tmp;
} a[N];

bool px(myd x, myd y) {
	return x.tmp < y.tmp;
}
int t, cnt[5], ans, n;

void qc(int x) {
	int dy = cnt[x] - n / 2;
	for (int i = 1; i <= dy; i++)
		ans -= a[i].tmp;
}

void cz(int x, int zd) {
	if (zd == a[x].a) {
		cnt[1]++;
		a[x].tmp = zd - max(a[x].b, a[x].c);
	} else if (zd == a[x].b) {
		cnt[2]++;
		a[x].tmp = zd - max(a[x].a, a[x].c);
	} else {
		cnt[3]++;
		a[x].tmp = zd - max(a[x].b, a[x].a);
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			int zd = max(a[i].a, max(a[i].b, a[i].c));
			ans += zd;
			cz(i, zd);
		}
		sort(a + 1, a + n + 1, px);
		for (int i = 1; i <= 3; i++) {
			if (cnt[i] > n / 2)
				qc(i);
		}
		cout << ans << '\n';
		for (int i = 1; i <= 3; i++)
			cnt[i] = 0;
	}
	return 0;
}