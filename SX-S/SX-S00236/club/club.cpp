#include <bits/stdc++.h>
using namespace std;
long long t, n, maxv1 = LLONG_MIN, maxv2 = LLONG_MIN, s = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, v1, v2, v3,
                x;
long long s7 = 0, s8 = 0, s9 = 0, s10 = 0, s11 = 0, s12 = 0;
const int N = 2e4+10;
int d1[N][N], d2[13];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		s = 0;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> d1[i][j];
			}
		}
		if (n == 2) {
			for (int i = 1; i <= 2; i++) {
				s1 = 0;
				s2 = 0;
				s3 = 0;
				s4 = 0;
				s5 = 0;
				s6 = 0;
				for (int j = 1; j <= 3; j++) {
					s1 = 0;
					s2 = 0;
					s3 = 0;
					s4 = 0;
					s5 = 0;
					s6 = 0;

					s1 = s1 + d1[1][1] + d1[2][2];
					s2 = s2 + d1[1][1] + d1[2][3];
					s3 = s3 + d1[1][2] + d1[2][1];
					s4 = s4 + d1[1][2] + d1[2][3];
					s5 = s5 + d1[1][3] + d1[2][1];
					s6 = s6 + d1[1][3] + d1[2][2];
				}
			}
			if (s1 > maxv1) {
				maxv1 = s1;
				if (s2 > maxv1) {
					maxv1 = s2;
				} else {
					if (s3 > maxv1) {
						maxv1 = s3;
					} else {
						if (s4 > maxv1) {
							maxv1 = s4;
						} else {
							if (s5 > maxv1) {
								maxv1 = s5;
							} else {
								if (s6 > maxv1) {
									maxv1 = s6;
								}
							}
						}
					}
				}
			}
			cout << maxv1;
		}
		if (n == 4) {

			for (int i = 1; i <= n; i++) {

				for (int j = 1; j <= 3; j++) {

					if (d1[i][j] > maxv1) {
						maxv1 = d1[i][j];
					}

					if (d1[i][1] == 0 && d1[i][3] == 0) {
						x = 4;
					}
				}
				s = s + maxv1;
			}

			cout << s << endl;
			cout << x << endl;
		}
	}
	return 0;

}
