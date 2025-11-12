#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010][5];
int a1[50010], a2[50010], a3[50010];
long long ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int N1 = 20010, N2 = 20010, N3 = 20010, sa1 = 0, sa2 = 0, sa3 = 0, ma1 = 0, ma2 = 0, ma3 = 0;
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				if (sa1 < n / 2) {
					a1[sa1] = i;
					sa1++;
					if (N1 > a[i][1] - max(a[i][2], a[i][3])) {
						ma1 = i;
						N1 = a[i][1] - max(a[i][2], a[i][3]);
					}
					ans += a[i][1];
				} else {
					if ( a[ma1][1] - max(a[ma1][2], a[ma1][3]) > a[i][1] - max(a[i][2], a[i][3]) ) {
						a[i][1] = -1;
					} else {
						ans = ans - a[ma1][1] + a[i][1];
						a[i][1] = -1;
						a[i][2] = a[ma1][2];
						a[i][3] = a[ma1][3];
						a1[ma1] = i;
						N1 = 20010;
					}
				}
			}
			if (a[i][2] > a[i][1] && a[i][2] >= a[i][3]) {
				if (sa2 < n / 2) {
					a2[sa2] = i;
					sa2++;
					if (N2 > a[i][2] - max(a[i][1], a[i][3])) {
						ma2 = i;
						N2 = a[i][2] - max(a[i][1], a[i][3]);
					}
					ans += a[i][2];
				} else {
					if ( a[ma2][2] - max(a[ma2][1], a[ma2][3]) > a[i][2] - max(a[i][1], a[i][3]) ) {
						a[i][2] = -1;
					} else {
						ans = ans - a[ma2][2] + a[i][2];
						a[i][1] = a[ma2][1];
						a[i][2] = -1;
						a[i][3] = a[ma2][3];
						a2[ma2] = i;
						N2 = 20010;
					}
				}
			}
			if (a[i][3] > a[i][1] && a[i][3] >= a[i][2]) {
				if (sa3 < n / 2) {
					a3[sa3] = i;
					sa3++;
					if (N3 > a[i][3] - max(a[i][2], a[i][1])) {
						ma3 = i;
						N3 = a[i][3] - max(a[i][2], a[i][1]);
					}
					ans += a[i][3];
				} else {
					if ( a[ma3][3] - max(a[ma3][2], a[ma3][1]) > a[i][3] - max(a[i][1], a[i][2]) ) {
						a[i][3] = -1;
					} else {
						ans = ans - a[ma3][3] + a[i][3];
						a[i][1] = a[ma3][1];
						a[i][2] = a[ma3][2];
						a[i][3] = -1;
						a3[ma3] = i;
						N3 = 20010;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
