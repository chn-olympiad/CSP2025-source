#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
int t, n, ans, cnt1, cnt2, cnt3;
int a[10][M][10], f[M][10];

struct q {
	int dis;
} d1[M], d2[M], d3[M];

int comp(q a, q b) {
	return a.dis < b.dis ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		ans = 0;
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j][1] >> a[i][j][2] >> a[i][j][3];
			if (a[i][j][1] >= a[i][j][2] && a[i][j][1] >= a[i][j][3]) {
				ans += a[i][j][1];
				d1[j].dis = a[i][j][1] - max(a[i][j][2], a[i][j][3]);
				d2[j].dis = M;
				d3[j].dis = M;
				cnt1++;
			} else if (a[i][j][2] >= a[i][j][3]) {
				ans += a[i][j][2];
				d2[j].dis = a[i][j][2] - max(a[i][j][1], a[i][j][3]);
				d3[j].dis = M;
				d1[j].dis = M;
				cnt2++;
			} else {
				ans += a[i][j][3];
				d3[j].dis = a[i][j][3] - max(a[i][j][2], a[i][j][1]);
				d2[j].dis = M;
				d1[j].dis = M;
				cnt3++;
			}
		}
		sort(d1 + 1, d1 + n + 1, comp);
		sort(d2 + 1, d2 + n + 1, comp);
		sort(d3 + 1, d3 + n + 1, comp);
		if (cnt1 > n / 2) {
			for (int i = 1; i <= cnt1 - n / 2; i++) {
				ans -= d1[i].dis;
			}
		}
		if (cnt2 > n / 2) {
			for (int i = 1; i <= cnt2 - (n / 2); i++) {
				ans -= d2[i].dis;
			}
		}
		if (cnt3 > n / 2) {
			for (int i = 1; i <= cnt3 - n / 2; i++) {
				ans -= d3[i].dis;
			}
		}
		cout << ans << endl;
	}
	return 0;
}



