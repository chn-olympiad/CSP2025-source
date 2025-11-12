#include <bits/stdc++.h>
using namespace std;

struct jjj {
	int a1, a2, a3;
} a[200005];
jjj aa[200005], ab[200005], ac[200005];
int g[200005];

int cmp(jjj x, jjj y) {
	if ((x.a1 - max(x.a2, x.a3)) < (y.a1 - max(y.a2, y.a3))) {
		return 1;
	}
	return 0;
}

int mpc(jjj x, jjj y) {
	if ((x.a2 - max(x.a1, x.a3)) < (y.a2 - max(y.a1, y.a3))) {
		return 1;
	}
	return 0;
}

int pcm(jjj x, jjj y) {
	if ((x.a3 - max(x.a2, x.a1)) < (y.a3 - max(y.a2, y.a1))) {
		return 1;
	}
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int sum1 = 0, sum2 = 0, sum3 = 0;
		long long sum = 0;
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].a1 >> a[j].a2 >> a[j].a3;
			if (a[j].a1 >= a[j].a2) {
				if (a[j].a1 >= a[j].a3) {
					g[j] = 1;
					sum1++;
					sum += a[j].a1;
					aa[sum1].a1 = a[j].a1;
					aa[sum1].a2 = a[j].a2;
					aa[sum1].a3 = a[j].a3;
				} else {
					g[j] = 3;
					sum3++;
					sum += a[j].a3;
					ac[sum3].a1 = a[j].a1;
					ac[sum3].a2 = a[j].a2;
					ac[sum3].a3 = a[j].a3;
				}
			} else {
				if (a[j].a2 >= a[j].a3) {
					g[j] = 2;
					sum2++;
					sum += a[j].a2;
					ab[sum2].a1 = a[j].a1;
					ab[sum2].a2 = a[j].a2;
					ab[sum2].a3 = a[j].a3;
				} else {
					g[j] = 3;
					sum3++;
					sum += a[j].a3;
					ac[sum3].a1 = a[j].a1;
					ac[sum3].a2 = a[j].a2;
					ac[sum3].a3 = a[j].a3;
				}
			}
		}
		if (sum1 > n / 2) {
			sort(aa + 1, aa + sum1 + 1, cmp);
			for (int k = 1; k <= sum1 - (n / 2); k++) {
				sum -= (aa[k].a1 - max(aa[k].a2, aa[k].a3));
			}
		} else if (sum2 > n / 2) {
			sort(ab + 1, ab + sum2 + 1, mpc);
			for (int k = 1; k <= sum2 - (n / 2); k++) {
				sum -= (ab[k].a2 - max(ab[k].a1, ab[k].a3));
			}
		} else if (sum3 > n / 2) {
			sort(ac + 1, ac + sum3 + 1, pcm);
			for (int k = 1; k <= sum3 - (n / 2); k++) {
				sum -= (ac[k].a3 - max(ac[k].a2, ac[k].a1));
			}
		}
		cout << sum << endl;
	}
	return 0;
}
