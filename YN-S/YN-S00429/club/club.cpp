#include <bits/stdc++.h>
using namespace std;
int t;
int a[100005][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		int rs = n / 2;
		int cntr[4], cntm[4];
		for (int i = 1; i <= 4; i++) {
			cntr[i] = 0;
			cntm[i] = 0;
		}
		int minlz1 = INT_MAX;
		int minlz2 = INT_MAX;
		int minlz3 = INT_MAX;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] < minlz1) {
				minlz1 = a[i][1];
			}
			if (a[i][2] < minlz2) {
				minlz2 = a[i][2];
			}
			if (a[i][3] < minlz3) {
				minlz3 = a[i][3];
			}
		}
//		cout << "minlz1:" << minlz1 << endl;
//		cout << "minlz2:" << minlz2 << endl;
//		cout << "minlz3:" << minlz3 << endl;
//		cout << endl;
		for (int i = 1; i <= n; i++) {
			int max_i = max(a[i][1], max(a[i][2], a[i][3]));
			int min_i = min(a[i][1], min(a[i][2], a[i][3]));
			if (max_i == a[i][1]) {
				if (cntr[1] >= rs) {
					if (min_i == a[i][2]) {
						if (cntr[3] >= rs) {
							cntr[2]++;
							cntm[2] += a[i][2];
						} else {
							cntr[3]++;
							cntm[3] += a[i][3];
						}
					}
				} else {
					cntr[1]++;
					cntm[1] += a[i][1];
				}
			} else if (max_i == a[i][2]) {
				if (cntr[2] >= rs) {
					if (min_i == a[i][3]) {
						if (cntr[1] >= rs) {
							cntr[3]++;
							cntm[3] += a[i][3];
						} else {
							cntr[1]++;
							cntm[1] += a[i][1];
						}
					}
				} else {
					cntr[2]++;
					cntm[2] += a[i][2];
				}
			} else if (max_i == a[i][3]) {
				if (cntr[3] >= rs) {
					if (min_i == a[i][2]) {
						if (cntr[1] >= rs) {
							cntr[2]++;
							cntm[2] += a[i][2];
						} else {
							cntr[1]++;
							cntm[1] += a[i][1];
						}
					}
				} else {
					cntr[3]++;
					cntm[3] += a[i][3];
				}
			}
//			cout << "cntm1:" << cntm[1] << " " << "cntm2:" << cntm[2] << " " << "cntm3:" << cntm[3] << endl;
//			cout << "cntr1:" << cntr[1] << " " << "cntr2:" << cntr[2] << " " << "cntr3:" << cntr[3] << endl;
		}
		ans = cntm[1] + cntm[2] + cntm[3];
//		cout << endl;
		if (cntr[1] > rs) {
			while (cntr[1] > rs) {
				if (minlz1 == 0) {
					minlz1 = 1;
				}
				ans -= minlz1;
				cntr[1]--;
//				cout << "1cntm1:" << cntm[1] << " " << "1cntm2:" << cntm[2] << " " << "1cntm3:" << cntm[3] << endl;
//				cout << "1cntr1:" << cntr[1] << " " << "1cntr2:" << cntr[2] << " " << "1cntr3:" << cntr[3] << endl;
			}
		} else if (cntr[2] > rs) {
			while (cntr[2] > rs) {
				if (minlz2 == 0) {
					minlz2 = 1;
				}
				ans -= minlz2;
				cntr[2]--;
//				cout << "2cntm1:" << cntm[1] << " " << "2cntm2:" << cntm[2] << " " << "2cntm3:" << cntm[3] << endl;
//				cout << "2cntr1:" << cntr[1] << " " << "2cntr2:" << cntr[2] << " " << "2cntr3:" << cntr[3] << endl;
			}
		} else if (cntr[3] > rs) {
			while (cntr[3] > rs) {
				if (minlz3 == 0) {
					minlz3 = 1;
				}
				ans -= minlz3;
				cntr[3]--;
//				cout << "3cntm1:" << cntm[1] << " " << "3cntm2:" << cntm[2] << " " << "3cntm3:" << cntm[3] << endl;
//				cout << "3cntr1:" << cntr[1] << " " << "3cntr2:" << cntr[2] << " " << "3cntr3:" << cntr[3] << endl;
			}
		}
//		cout << endl;
//		cout << "dcntm1:" << cntm[1] << " " << "dcntm2:" << cntm[2] << " " << "dcntm3:" << cntm[3] << endl;
//		cout << "dcntr1:" << cntr[1] << " " << "dcntr2:" << cntr[2] << " " << "dcntr3:" << cntr[3] << endl;
		cout << ans << "\n";
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/