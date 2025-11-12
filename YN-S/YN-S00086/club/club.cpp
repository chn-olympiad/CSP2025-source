#include <bits/stdc++.h>
using namespace std;
int t, n, o, num[5], tt, hh, ss;

struct mb {
	int s[5], mn, fi, se, th, d1, d2, d3;
} a[100005];
bool b[100005], c[5];

int fc(int pp) {
	for (int i = pp; i < n; i++) {

		a[i].mn = max(a[i].s[1], max(a[i].s[2], a[i].s[3] ));

		if (a[i].mn == a[i].s[1]) {
			a[i].fi = 1;
			if (a[i].s[2] >= a[i].s[3]) {
				a[i].se = 2;
				a[i].th = 3;
			} else {
				a[i].se = 3;
				a[i].th = 2;
			}
		} else if (a[i].mn == a[i].s[2] ) {
			a[i].fi = 2;
			if (a[i].s[1] >= a[i].s[3]) {
				a[i].se = 1;
				a[i].th = 3;
			} else {
				a[i].se = 3;
				a[i].th = 1;
			}
		} else {
			a[i].fi = 3;
			if (a[i].s[1] >= a[i].s[2]) {
				a[i].se = 1;
				a[i].th = 2;
			} else {
				a[i].se = 2;
				a[i].th = 1;
			}
		}


		a[i].d3 = -a[i].s[a[i].se] + a[i].s[a[i].th];
		a[i].d2  = 0;
		a[i].d1 =	a[i].s[a[i].fi] - a[i].s[a[i].se] ;
//		cout << a[i].d1 << endl;

	}
	return 0;
}

bool cmp(mb x, mb y) {
	return x.d1 > y.d1;
}
long long ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		o = n / 2;
		for (int i = 0; i < 5; i++) {
			num[i] = 0;
			c[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i].s[1] >> a[i].s[2] >> a[i].s[3];
		}
		fc(0);
		sort(a, a + n, cmp);
		ans = 0;
		for (int i = 0; i < n; i++) {

			tt = a[i].fi;
//			cout << a[i].d1 << endl;
			ans += a[i].s[tt];
			num[tt]++;
			if (num[tt] == o) {
				for (int j = i + 1; j < n; j++) {
					a[j].s[tt] = 0;
				}
				fc(i + 1);
				sort(a + i + 1, a + n, cmp);
			}
		}
		cout << ans << endl;
	}
	return 0;
}