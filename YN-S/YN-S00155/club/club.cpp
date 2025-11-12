#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][3], cnt, p[100005], b[4], ans, flag, flag1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n;
		ans = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt = 0;
			for (int k = 1; k <= 3; k++) {

				cin >> a[i][k];
				if (cnt < a[i][k]) {
					cnt = a[i][k], p[i] = k;

				}

			}
			if (a[i][2] == 0 && a[i][3] == 0) {
				flag1 = 1;
			}
			b[p[i]]++;
		}
		for (int i = 1; i <= 3; i++) {
			if (b[i] > n / 2)
				flag = 1;
		}


		for (int k = 1; k <= n; k++) {
			ans += a[k][p[k]];
		}
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= 3; k++) {
				a[i][k] = 0;
				p[i] = 0;
			}
		}


		cout << ans;
	}
	return 0;
}
