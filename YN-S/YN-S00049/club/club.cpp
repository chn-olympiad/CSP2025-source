#include <bits/stdc++.h>

using namespace std;
struct fls {
	int bj;
	int dx;
};

bool smp(fls a, fls b) {
	return a.dx < b.dx;
}
fls fl1[100005], fl2[100005], fl3[100005];

int sum = 0, cnt [4] = {0};
int t, n;
int a[100005][4];




int st1(int i) {
	if ( a[i][2] >= a[i][3]) {
		return a[i][2];
	} else  {
		return a[i][3];

	}
}

int st2(int i) {
	if ( a[i][1] >= a[i][3]) {
		return a[i][1];

	} else  {
		return a[i][3];

	}
}

int st3(int i) {
	if ( a[i][1] >= a[i][2]) {
		return a[i][1];

	} else  {
		return a[i][2];

	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int s = 0; s < t; s++) {
		cin >> n;
		cnt[4] = {0};
		sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		int da[4] = {0};
		int wz1 = 0, wz2 = 0, wz3 = 0, wz4 = 0;
		for (int i = 1; i <= n; i++) {

			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				if (cnt[1] < n / 2) {
					if (a[i][1] >= da[1]) {
						da[1] = a[i][1];
						sum += a[i][1];
						cnt[1]++;

						fl1[wz1].bj = i;
						fl1[wz1].dx = a[i][1];
						wz1 += 1;
					} else  {
						sum += a[i][1];
						cnt[1]++;

						fl1[wz1].bj = i;
						fl1[wz1].dx = a[i][1];
						wz1 += 1;

					}
					sort(fl1 + 1, fl1 + 1 + wz1, smp);
				} else if ( a[i][1] > fl1[1].dx  ) {
					sum = sum - fl1[1].dx + a[i][1] + st1(fl1[1].bj);
					wz1 += 1;
					fl1[wz1].bj = i;
					fl1[wz1].dx = a[i][1];
				} else {
					if (a[i][2] >= a[i][3] && cnt[2] <= n / 2) {
						sum += a[i][2];
						cnt[2]++;
					} else {
						sum += a[i][3];
						cnt[3]++;
					}
				}
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				if (cnt[2] < n / 2) {
					if (a[i][2] >= da[2]) {
						da[2] = a[i][2];
						sum += a[i][2];
						cnt[2]++;

						fl2[wz2].bj = i;
						fl2[wz2].dx = a[i][2];
						wz2 += 1;
					} else  {
						sum += a[i][2];
						cnt[2]++;

						fl2[wz2].bj = i;
						fl2[wz2].dx = a[i][2];
						wz2 += 1;
					}
					sort(fl2 + 1, fl2 + 1 + wz2, smp);
				} else if (a[i][2] > fl1[1].dx  ) {
					sum = sum - fl2[1].dx + a[i][2] + st2(fl2[1].bj);
					wz2 += 1;
					fl2[wz2].bj = i;
					fl2[wz2].dx = a[i][2];
				} else {
					if (a[i][1] >= a[i][3] && cnt[1] <= n / 2) {
						sum += a[i][1];
						cnt[1]++;
					} else {
						sum += a[i][3];
						cnt[3]++;
					}
				}
			} else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {
				if (cnt[3] < n / 2) {
					if (a[i][3] >= da[3]) {
						da[3] = a[i][3];
						sum += da[3];
						cnt[3]++;

						fl3[wz3].bj = i;
						fl3[wz3].dx = a[i][3];
						wz3 += 1;
					} else  {
						sum += a[i][3];
						cnt[3]++;

						fl3[wz3].bj = i;
						fl3[wz3].dx = a[i][3];
						wz3 += 1;
					}
					sort(fl3 + 1, fl3 + 1 + wz3, smp);
				} else if ( a[i][3] > fl1[1].dx ) {
					sum = sum - fl3[1].dx + a[i][3] + st3(fl3[1].bj);
					wz3 += 1;
					fl3[wz3].bj = i;
					fl3[wz3].dx = a[i][3];
				} else {
					if (a[i][1] >= a[i][2] && cnt[1] <= n / 2) {
						sum += a[i][1];
						cnt[1]++;
					} else {
						sum += a[i][2];
						cnt[2]++;
					}
				}
			}

		}
		cout << sum << endl;
	}
	return 0;
}