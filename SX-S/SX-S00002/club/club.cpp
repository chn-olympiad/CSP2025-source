#include <bits/stdc++.h>

using namespace std;
int ans1[10];

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);



	int  t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int  n;
		cin >> n;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		struct gp {
			int a1, a2, a3;
		} g[100005] ;

		for (int j = 1; j <= n; j++) {
			cin >> g[j].a1 >> g[j].a2 >> g[j].a3;
		}
		for (int x = 1; x <= n; x++) {
			for (int j = 1; j < n; j++) {
				int m = g[j].a3, n1 = g[j + 1].a3;
				swap(m, n1);
			}
		}
		for (int j = 1; j <= n; j++) {
			if (g[j].a1 >= g[j].a2 && g[j].a1 >= g[j].a3) {
				if (cnt1 <= n / 2) {
					cnt1++;
					ans += g[j].a1;
				} else if (g[j].a2 >= g[j].a3 && cnt2 <= n / 2) {
					cnt2++;
					ans += g[j].a2;
				} else {
					cnt3++;
					ans += g[j].a3;
				}
			}
			if (g[j].a2 >= g[j].a1 && g[j].a2 >= g[j].a3) {
				if (cnt2 <= n / 2) {
					cnt2++;
					ans += g[j].a2;
				} else if (g[j].a1 >= g[j].a3 && cnt1 < n / 2) {
					cnt1++;
					ans += g[j].a1;
				} else {
					cnt3++;
					ans += g[j].a3;
				}
			}
			if (g[j].a3 >= g[j].a1 && g[j].a3 >= g[j].a2) {
				if (cnt3 < n / 2) {
					cnt3++;
					ans += g[j].a3 ;
				} else if (g[j].a1 >= g[j].a2 && cnt1 < n / 2) {
					cnt1++;
					ans += g[j].a1;
				} else {
					cnt2++;
					ans += g[j].a2;
				}
			}
		}

		ans1[i] = ans;
	}
	for (int i = 1; i <= t; i++) {
		cout << ans1[i]  << "\n";
	}

	return 0;
}
