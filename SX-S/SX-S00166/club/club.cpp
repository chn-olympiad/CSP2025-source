#include <bits/stdc++.h>
using namespace std;

struct ru {
	int a1;
	int a2;
	int a3;
	int max1 = 0;
	int max2 = 0;
	int bm;
};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int n;
		cin >> n;
		long long max11 = 0;
		ru a[n + 2];
		long long sum1 = 0, sum2 = 0, sum3 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if (a[i].a1 != a[i].a2 || a[i].a1 != a[i].a3 || a[i].a2 != a[i].a3)
				a[i].max1 = max(a[i].a1, max(a[i].a2, a[i].a3));
			else if (a[i].a1 == a[i].a2 && a[i].a2 == a[i].a3) {
				a[i].max1 = a[i].a1;
				a[i].max2 = a[i].a1;
			}
			if (a[i].max1 == a[i].a1) {
				a[i].bm = 1;
				sum1 += 1;
				if (a[i].a2 == a[i].a3) {
					a[i].max2 = a[i].a2;
				} else {
					a[i].max2 = max(a[i].a2, a[i].a3);
				}
			}
			if (a[i].max1 == a[i].a2) {
				a[i].bm = 2;
				sum2 += 1;
				if (a[i].a1 == a[i].a3) {
					a[i].max2 = a[i].a1;
				} else {
					a[i].max2 = max(a[i].a1, a[i].a3);
				}
			}
			if (a[i].max1 == a[i].a3) {
				a[i].bm = 3;
				sum3 += 1;
				if (a[i].a1 == a[i].a2) {
					a[i].max2 = a[i].a1;
				} else {
					a[i].max2 = max(a[i].a1, a[i].a2);
				}
			}

		}
		if (sum1 > n / 2) {
			while (sum1 > n / 2) {
				int minn = 2000000;
				for (int i = 1; i <= n; i++) {
					if (a[i].bm == 1)
						minn = min(a[i].max1 - a[i].max2, minn);
				}
				for (int i = 1; i <= n; i++) {
					if (a[i].max1 - a[i].max2 == minn) {
						a[i].max1 = a[i].max2;
						if (a[i].max1 == a[i].a2) {
							a[i].bm = 2;
							sum1 -= 1;
							sum2 += 1;
						} else if (a[i].max1 == a[i].a3) {
							a[i].bm = 3;
							sum1 -= 1;
							sum3 += 1;
						}
					}
				}
			}
		}
		if (sum2 > n / 2) {
			while (sum2 > n / 2) {
				int minn = 2000000;
				for (int i = 1; i <= n; i++) {
					if (a[i].bm == 2)
						minn = min(a[i].max1 - a[i].max2, minn);
				}
				for (int i = 1; i <= n; i++) {
					if (a[i].max1 - a[i].max2 == minn) {
						a[i].max1 = a[i].max2;
						if (a[i].max1 == a[i].a1) {
							a[i].bm = 1;
							sum2 -= 1;
							sum1 += 1;
						} else if (a[i].max1 == a[i].a3) {
							a[i].bm = 3;
							sum2 -= 1;
							sum3 += 1;
						}
					}
				}
			}
		}
		if (sum3 > n / 2) {
			while (sum3 > n / 2) {
				int minn = 2000000;
				for (int i = 1; i <= n; i++) {
					if (a[i].bm == 3)
						minn = min(a[i].max1 - a[i].max2, minn);
				}
				for (int i = 1; i <= n; i++) {
					if (a[i].max1 - a[i].max2 == minn) {
						a[i].max1 = a[i].max2;
						if (a[i].max1 == a[i].a2) {
							a[i].bm = 2;
							sum3 -= 1;
							sum2 += 1;
						} else if (a[i].max1 == a[i].a1) {
							a[i].bm = 1;
							sum3 -= 1;
							sum1 += 1;
						}
					}
				}
			}
		}
		//if (sum1 <= n / 2 && sum2 <= n / 2 && sum3 <= n / 2) {
		for (int i = 1; i <= n; i++) {
			max11 += a[i].max1;
		}
		//}
		cout << max11 << endl;
	}
	return 0;
}
