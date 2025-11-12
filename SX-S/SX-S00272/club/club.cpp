#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	int n;
	int m = 1;
	int sum[t + 3] = {};
	for (int i = 1; i <= t; i++) {

		int a[n + 3][6] = {};
		int s[5] = {};
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if ( max(a[i][1], max(a[i][2], a[i][3])) == a[i][1]) {
					if (s[1] < n / 2) {
						s[1]++;
						sum[m] += a[i][1];
						break;
					} else if (max(a[i][2], a[i][3]) == a[i][2]) {
						if (s[2] < n / 2) {
							s[2]++;
							sum[m] += a[i][2];
							break;
						} else if (s[3] < n / 2) {
							s[3]++;
							sum[m] += a[i][3];
							break;
						}
					}
				} else if ( max(a[i][1], max(a[i][2], a[i][3])) == a[i][2]) {
					if (s[2] < n / 2) {
						s[2]++;
						sum[m] += a[i][2];
						break;
					} else if (max(a[i][1], a[i][3]) == a[i][1]) {
						if (s[1] < n / 2) {
							s[1]++;
							sum[m] += a[i][1];
							break;
						} else if (s[3] < n / 2) {
							s[3]++;
							sum[m] += a[i][3];
							break;
						}
					}
				} else if ( max(a[i][1], max(a[i][2], a[i][3])) == a[i][3]) {
					if (s[3] < n / 2) {
						s[3]++;
						sum[m] += a[i][3];
						break;
					} else if (max(a[i][1], a[i][2]) == a[i][1]) {
						if (s[1] < n / 2) {
							s[1]++;
							sum[m] += a[i][1];
							break;
						} else if (s[2] < n / 2) {
							s[2]++;
							sum[m] += a[i][2];
							break;
						}
					}
				}
			}
		}
		m++;
//		for (int i = 1; i <= 3; i++) {
//			cout << s[i] << " ";
//		}
//		cout << endl;
	}
	for (int i = 1; i <= t; i++) {
		cout << sum[i] << endl;
	}
	return 0;
}