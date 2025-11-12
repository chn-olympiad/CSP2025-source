#include <bits/stdc++.h>
using namespace std;
int t, n,  mi = INT_MAX, ne, c = 1, c1 = 1;
int a[100005][5], vis[5][100005], se[100005][5];
int cha[100005], cnt[5], ma[100005], s[5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;

	for (int k = 1; k <= t; k++) {

		cin >> n;
		int f = n / 2;
		int sum = 0, sum1 = 0;

		for (int i = 1; i <= n; i++)

			cnt[i] = 0;

		for (int i = 1; i <= n; i++)

			ma[i] = 0;

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				cin >> a[i][j];

				if (a[i][j] > ma[i])
					ma[i] = a[i][j];
			}

			sum = sum + ma[i];

			for (int j = 1; j <= 3; j++) {

				if (a[i][j] == ma[i])
					cnt[j]++;
				vis[j][i] = 1;

			}

		}

		int flag1 = 1;

		for (int i = 1; i <= n; i++) {

			if (a[i][2] != 0 && a[i][3] != 0) {
				flag1 = 0;
			}
		}

		if (flag1) {
			sort(ma + 1, ma + n + 1);

			for (int i = n; i >= 1; i--) {

				if (c > f)
					break;
				sum1 = sum1 + ma[i];
				c++;
			}

			cout << sum1 << endl;
		} else {
			int flag = 1;

			for (int i = 1; i <= 3; i++) {

				if (cnt[i] > f) {
					flag = 0;
					ne = i;
				}

			}

			if (flag == 0) {

				for (int i = 1; i <= n; i++) {

					for (int j = 1; j <= 3; j++) {

						s[j] = ma[i] - a[i][j];
					}

					sort(s + 1, s + 4);
					cha[i] = s[2];
				}

				sort(cha + 1, cha + n + 1);

				while (cnt[ne] > f) {
					sum = sum - cha[c1];
					c1++;
					cnt[ne]--;
				}
			}


			cout << sum << endl;

		}

	}

	return 0;
}