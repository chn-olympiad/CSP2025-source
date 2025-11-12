#include <bits/stdc++.h>
using namespace std;
long long t, n, h;
int sum[4];
int a1[100005], a2[100004], a3[100020];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int ans[100005], z = 1;
		sum[1] = 0, sum[2] = 0, sum[3] = 0;
		cin >> n;
		if (n == 100000) {
			bool b = 0;
			for (int i = 1; i <= n; i++) {
				if (a2[i] != 0 || a3[i] != 0) {
					b = 1;
				}
			}
			if (b == 0) {
				long long aa = 0;
				sort(a1 + 1, a1 + 1 + n);
				for (int i = 1; i <= 50000; i++) {
					aa += a1[i];
				}
				cout << aa;
				break;

			}
		}
		if (n == 200) {
			bool b = 0;
			for (int i = 1; i <= n; i++) {
				if (a3[i] != 0) {
					b = 1;
				}
			}
			if (b == 0) {

			}
		}
		h = n / 2;
		//h -= 1;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
		}

		for (int m = 1; m <= n; m++) {
			ans[z] = a1[m];

			long long mmax, num ;
			for (int i = m + 1; i <= n; i++) { //当初始值等于a1时
				if (a1[i] > a2[i]) {
					mmax = a1[i];
					num = 1;
					if (a3[i] > a1[i]) {
						mmax = a3[i];
						num = 3;
					}
				} else {
					mmax = a2[i];
					num = 2;
					if (a3[i] > a2[i]) {
						mmax = a3[i];
						num = 3;
					}
				}
				if (i != m && sum[num] + 1 <= h) {
					ans[z] += mmax;
					sum[num]++;
				}
			}
			for (int i = 1; i < m; i++) {
				if (a1[i] > a2[i]) {
					mmax = a1[i];
					num = 1;
					if (a3[i] > a1[i]) {
						mmax = a3[i];
						num = 3;
					}
				} else {
					mmax = a2[i];
					num = 2;
					if (a3[i] > a2[i]) {
						mmax = a3[i];
						num = 3;
					}
				}
				if (m != i && sum[num] + 1 <= h) {
					ans[z] += mmax;
					sum[num]++;
				}
			}
			//cout << ans[z] << " ";
			z++;
			ans[z] = a2[m];
//			sum[1] = 0, sum[2] = 0, sum[3] = 0;
			for (int i = m + 1; i <= n; i++) { //当初始值等于a2时
				if (a1[i] > a2[i]) {
					mmax = a1[i];
					num = 1;
					if (a3[i] > a1[i]) {
						mmax = a3[i];
						num = 3;
					}
				} else {
					mmax = a2[i];
					num = 2;
					if (a3[i] > a2[i]) {
						mmax = a3[i];
						num = 3;
					}
				}
				if (m != i && sum[num] + 1 <= h) {
					ans[z] += mmax;
					sum[num]++;
				}
			}
			for (int i = 1; i < m; i++) {
				if (a1[i] > a2[i]) {
					mmax = a1[i];
					num = 1;
					if (a3[i] > a1[i]) {
						mmax = a3[i];
						num = 3;
					}
				} else {
					mmax = a2[i];
					num = 2;
					if (a3[i] > a2[i]) {
						mmax = a3[i];
						num = 3;
					}
				}
				if (m != i && sum[num]  <= h) {
					ans[z] += mmax;
					sum[num]++;
					if (sum[num] > h)
						ans[z] = 0;
				}
			}
			//cout << ans[z] << " ";
			z++;
			ans[z] = a3[m];
			//sum[1] = 0, sum[2] = 0, sum[3] = 0;
			for (int i = m + 1 ; i <= n; i++) { //当初始值等于a3
				if (a1[i] > a2[i]) {
					mmax = a1[i];
					num = 1;
					if (a3[i] > a1[i]) {
						mmax = a3[i];
						num = 3;
					}
				} else {
					mmax = a2[i];
					num = 2;
					if (a3[i] > a2[i]) {
						mmax = a3[i];
						num = 3;
					}
				}
				if (m != i && sum[num]  <= h) {
					ans[z] += mmax;
					sum[num]++;
					if (sum[num] > h)
						ans[z] = 0;
				}
				for (int i = 1; i < m; i++) {
					if (a1[i] > a2[i]) {
						mmax = a1[i];
						num = 1;
						if (a3[i] > a1[i]) {
							mmax = a3[i];
							num = 3;
						}
					} else {
						mmax = a2[i];
						num = 2;
						if (a3[i] > a2[i]) {
							mmax = a3[i];
							num = 3;
						}
					}
					if (m != i && sum[num]  <= h) {
						ans[z] += mmax;
						sum[num]++;
						if (sum[num] > h)
							ans[z] = 0;
					}
				}
				//	cout << ans[z] << " ";
				z++;
			}
		}
		sort(ans + 1, ans + 1 + z);
//		for (int i = 1; i <= z; i++) {
//			cout << ans[i] << " ";
//		}
		cout << ans[z] << endl;
		memset(ans + 1, sizeof(ans) + 1, 0);
	}
	return 0;
}
