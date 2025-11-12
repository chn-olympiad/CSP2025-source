#include <bits/stdc++.h>
using namespace std;
int a[100005][5];

int b[100005];
int mmax = INT_MIN;
int t, n, sum = 0;
int sum1, sum2, sum3;

bool cmp(int p, int q) {
	return p > q;
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];


		}
		if (n <= 14) {
			mmax = 0;
			for (int i1 = 1; i1 <= 3; i1++) {

				for (int i2 = 1; i2 <= 3; i2++) {
					for (int i3 = 1; i3 <= 3; i3++) {
						for (int i4 = 1; i4 <= 3; i4++) {
							for (int i5 = 1; i5 <= 3; i5++) {
								for (int i6 = 1; i6 <= 3; i6++) {
									for (int i7 = 1; i7 <= 3; i7++) {
										for (int i8 = 1; i8 <= 3; i8++) {
											for (int i9 = 1; i9 <= 3; i9++) {
												for (int i10 = 1; i10 <= 3; i10++) {
													sum1 = 0;
													sum2 = 0;
													sum3 = 0;
													sum = 0;
													if (n == 2) {
														i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0, i10 = 0;
													}
													if (n == 4)
														i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0, i10 = 0;
													if (n == 6)
														i7 = 0, i8 = 0, i9 = 0, i10 = 0;
													if (n == 8)
														i9 = 0, i10 = 0;
													if (i1 == 1)
														sum1++;
													if (i1 == 2)
														sum2++;
													if (i1 == 3)
														sum3++;
													if (i2 == 1)
														sum1++;
													if (i2 == 2)
														sum2++;
													if (i2 == 3)
														sum3++;
													if (i3 == 1)
														sum1++;
													if (i3 == 2)
														sum2++;
													if (i3 == 3)
														sum3++;
													if (i4 == 1)
														sum1++;
													if (i4 == 2)
														sum2++;
													if (i4 == 3)
														sum3++;
													if (i5 == 1)
														sum1++;
													if (i5 == 2)
														sum2++;
													if (i5 == 3)
														sum3++;
													if (i6 == 1)
														sum1++;
													if (i6 == 2)
														sum2++;
													if (i6 == 3)
														sum3++;
													if (i7 == 1)
														sum1++;
													if (i7 == 2)
														sum2++;
													if (i7 == 3)
														sum3++;
													if (i8 == 1)
														sum1++;
													if (i8 == 2)
														sum2++;
													if (i8 == 3)
														sum3++;
													if (i9 == 1)
														sum1++;
													if (i9 == 2)
														sum2++;
													if (i9 == 3)
														sum3++;
													if (i10 == 1)
														sum1++;
													if (i10 == 2)
														sum2++;
													if (i10 == 3)
														sum3++;
													if (sum1 > n / 2 || sum2 > n / 2 || sum3 > n / 2)
														continue;
													mmax = max(a[1][i1] + a[2][i2] + a[3][i3] + a[4][i4] + a[5][i5] + a[6][i6] + a[7][i7] + a[8][i8] + a[9][i9] +
													           a[10][i10], mmax);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout << mmax << endl;

		} else {
			for (int i = 1; i <= n; i++) {
				b[i] = a[i][1];
			}
			sort(b + 1, b + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				sum += b[i];
			}
			cout << sum << endl;
		}

	}
	return 0;
}