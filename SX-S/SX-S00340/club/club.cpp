#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][5];
int cnt, maxn, a_1, a_2, a_3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		maxn = n / 2;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 3; k++) {
				cin >> a[j][k];
			}
			if (a[j][1] > a[j][2] && a[j][1] > a[j][3] && maxn != a_1) {
				a_1++;
				cnt += a[j][1];
			} else if (a[j][2] > a[j][1] && a[j][2] > a[j][3] && maxn != a_2) {
				a_2++;
				cnt += a[j][2];
			} else if (a[j][3] > a[j][1] && a[j][3] > a[j][2] && maxn != a_3) {
				a_3++;
				cnt += a[j][3];
			} else if (a[j][1] > a[j][2] && a[j][1] > a[j][3] && maxn == a_1 && a[j][2] >= a[j][3]) {
				a_2++;
				cnt += a[j][2];
			} else if (a[j][1] > a[j][2] && a[j][1] > a[j][3] && maxn == a_1 && a[j][3] > a[j][2]) {
				a_3++;
				cnt += a[j][3];
			} else if (a[j][2] > a[j][1] && a[j][2] > a[j][3] && maxn == a_2 && a[j][1] >= a[j][3]) {
				a_1++;
				cnt += a[j][1];
			} else if (a[j][2] > a[j][3] && a[j][2] > a[j][1] && maxn == a_2 && a[j][3] > a[j][1]) {
				a_3++;
				cnt += a[j][3];
			} else if (a[j][3] > a[j][1] && a[j][3] > a[j][2] && maxn == a_3 && a[j][1] >= a[j][2]) {
				a_1++;
				cnt += a[j][1];
			} else if (a[j][3] > a[j][2] && a[j][3] > a[j][1] && maxn == a_3 && a[j][2] > a[j][1]) {
				a_2++;
				cnt += a[j][2];
			}
		}
		cout << cnt;
		cnt = 0;
		a_1 = 0;
		a_2 = 0;
		a_3 = 0;
	}
	return 0;
}