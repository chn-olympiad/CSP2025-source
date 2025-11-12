#include <bits/stdc++.h>
using namespace std;
int n;
int x[100005], y[100005], z[100005];

struct ch {
	int w, i;
};
ch a1[100005], a2[100005], a3[100005];

int sum1[100005], sum2[100005], sum3[100005];


bool cmp(ch a, ch b) {
	return a.w > b.w;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		cin >> n;
		int f = 1;
		for (int i = 1; i <= n; i++) {
			a1[i].w == 0;
		}
		for (int i = 1; i <= n; i++) {
			a2[i].w == 0;
		}
		for (int i = 1; i <= n; i++) {
			a3[i].w == 0;
		}
		int  ans = 0;
		for (int i = 1; i <= n; i++) {

			cin >> x[i] >> y[i] >> z[i];
			int a = max(max(x[i], y[i]), z[i]);
			a1[i].i = i;
			a2[i].i = i;
			a3[i].i = i;
			if (y[i] != 0 || z[i] != 0) {
				f = 0;
			}
			if (a == x[i]) {
				a1[i].w = a;
				cnt1++;
			} else if (a == y[i]) {
				a2[i].w = a;
				cnt2++;

			} else if (a == z[i]) {
				a3[i].w = a;
				cnt3++;

			}
		}

		if (f == 1) {

			sort(a1 + 1, a1 + 1 + n, cmp);
			sum1[1] = a1[1].w;
			for (int i = 2; i <= n / 2; i++) {
				sum1[i] = sum1[i - 1] + a1[i].w;
			}
			cout << sum1[n / 2] << endl;
		} else {
			sort(a1 + 1, a1 + 1 + n, cmp);
			sort(a2 + 1, a2 + 1 + n, cmp);
			sort(a3 + 1, a3 + 1 + n, cmp);
			sum1[1] = a1[1].w;
			sum2[1] = a2[1].w;
			sum3[1] = a3[1].w;
			for (int i = cnt1 + 1; i <= n; i++) {
				a1[i].w = x[a1[i].i];
			}
			for (int i = cnt2 + 1; i <= n; i++) {
				a2[i].w = y[a2[i].i];
			}
			for (int i = cnt3 + 1; i <= n; i++) {
				a3[i].w = z[a3[i].i];
			}
			sort(a1 + 1 + cnt1, a1 + 1 + n, cmp);
			sort(a2 + 1 + cnt2, a2 + 1 + n, cmp);
			sort(a3 + 1 + cnt3, a3 + 1 + n, cmp);
			int ln = n / 3;
			for (int i = 2; i <= n / 2; i++) {
				sum1[i] = sum1[i - 1] + a1[i].w;
				sum2[i] = sum2[i - 1] + a2[i].w;
				sum3[i] = sum3[i - 1] + a3[i].w;
			}
			if (n <= 200) {
				sum1[1] = x[1];
				sum2[1] = y[1];
				sum3[1] = z[1];
				for (int i = 2; i <= n / 2; i++) {
					sum1[i] = sum1[i - 1] + x[i];
					sum2[i] = sum2[i - 1] + y[i];
					sum3[i] = sum3[i - 1] + z[i];
				}
				int ans1 = 0;
				for (int i = 1; i <= n / 2; i++) {
					for (int j = n / 2 - i; j <= n / 2; j++) {
						int k = n - i - j;
						ans1 = sum1[i] + sum2[j] + sum3[k];
						ans = max(ans, ans1);
					}
				}

			}

			if (n % 3 == 0) {
				ans = sum1[ln] + sum2[ln] + sum3[ln];
			}
			if (n % 3 == 1) {

				ans = max(max(sum1[ln], sum2[ln]), sum3[ln]);
				if (ans == sum1[ln]) {
					ans += sum2[ln - 1] + sum3[ln - 1];
				} else if (ans == sum2[ln]) {
					ans += sum1[ln - 1] + sum3[ln - 1];
				} else if (ans == sum3[ln]) {
					ans += sum2[ln - 1] + sum1[ln - 1];
				}
			}

			if (n % 3 == 2) {

				ans = max(max(sum1[ln], sum2[ln]), sum3[ln]);
				if (ans == sum1[ln]) {
					int ma = max(sum2[ln], sum3[ln]);
					if (ma == sum2[ln]) {
						ans += sum2[ln] + sum3[ln - 1];
					} else {
						ans += sum2[ln - 1] + sum3[ln];
					}
				} else if (ans == sum2[ln]) {
					int ma = max(sum1[ln], sum3[ln]);
					if (ma == sum1[ln]) {
						ans += sum1[ln] + sum3[ln - 1];
					} else {
						ans += sum1[ln - 1] + sum3[ln];
					}
				} else if (ans == sum3[ln]) {
					int ma = max(sum2[ln], sum1[ln]);
					if (ma == sum2[ln]) {
						ans += sum2[ln] + sum1[ln - 1];
					} else {
						ans += sum2[ln - 1] + sum1[ln];
					}
				}
			}


			cout << ans << endl;
		}
	}



	return 0;
}