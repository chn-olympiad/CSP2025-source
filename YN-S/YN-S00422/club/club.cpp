#include <bits/stdc++.h>
using namespace std;
int T, n, ans, sum1, sum2, id1, id2;

struct ww {
	int a1, a2, a3, id;
} a[100005];

int cmp(ww a, ww b) {
	return a.a1 > b.a1;
}

int cmp1(ww a, ww b) {
	return a.a2 > b.a2;
}

int main() {
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		bool flag1 = true, flag2 = true, flag3 = true;
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++ ) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			id1 += a[i].a1;
			id2 += a[i].a2;
			if (a[i].a2 != 0) {
				flag2 = false;
			}
			if (a[i].a3 != 0) {
				flag3 = false;
			}
		}
		if (n == 2) {
			ans = max(max(max(a[1].a2 + a[2].a1, a[1].a2 + a[2].a3), max(a[1].a1 + a[2].a2, a[1].a1 + a[2].a3)),
			          max(a[1].a3 + a[2].a1,
			              a[1].a3 + a[2].a2));
			cout << ans << endl;
			continue;
		}
		if (flag2 && flag3) {
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].a1;
			}
			cout << ans << endl;
			continue;
		}
		if (flag2 || flag3) {
			if (id1 > id2) {
				sort(a + 1, a + n + 1, cmp);
				for (int i = 1; i <= n; i++) {

					ans += max(a[i].a1, a[i].a2);
					if (max(a[i].a1, a[i].a2) == a[i].a1) {
						sum1++;
					} else {
						sum2++;
					}
					if (sum1 == n / 2) {
						for (int j = i + 1; j <= n; j++) {
							ans += a[j].a2;
						}
					} else if (sum2 == n / 2) {
						for (int j = i + 1; j <= n; j++) {
							ans += a[j].a1;
						}
					}
				}
				cout << ans << endl;
				continue;
			}
			if (id1 < id2) {
				sort(a + 1, a + n + 1, cmp1);
				for (int i = 1; i <= n; i++) {

					ans += max(a[i].a1, a[i].a2);
					if (max(a[i].a1, a[i].a2) == a[i].a1) {
						sum1++;
					} else {
						sum2++;
					}
					if (sum1 == n / 2) {
						for (int j = i + 1; j <= n; j++) {
							ans += a[j].a2;
						}
					} else if (sum2 == n / 2) {
						for (int j = i + 1; j <= n; j++) {
							ans += a[j].a1;
						}
					}
				}
				cout << ans << endl;
				continue;
			}

		}
		for (int i = 1; i <= n; i++) {
			ans += max(a[i].a1, max(a[i].a2, a[i].a3));
		}
		cout << ans << endl;

	}
	return 0;
}