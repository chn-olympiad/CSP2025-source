#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010][5], ans, b, c, sum;
bool f[100010];
double k[100010][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			k[i][1] = double(a[i][1]) / double(a[i][1] + a[i][2] + a[i][3]);
			k[i][2] = double(a[i][2]) / double(a[i][1] + a[i][2] + a[i][3]);
			k[i][3] = double(a[i][3]) / double(a[i][1] + a[i][2] + a[i][3]);
		}
		if (n < 3)
			c = 1;
		else
			c = n / 3;
		while (c--) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= n; j++) {
					if ((k[j][i] > k[b][i]) && (f[j] == 0)) {
						b = j;
					}
					if ((k[j][i] == k[b][i]) && (f[j] == 0) && (a[j][i] > a[b][i])) {
						b = j;
					}
				}
				ans += a[b][i];
				f[b] = 1;
				b = 0;
			}

		}
		for (int i = 1; i <= n; i++) {
			if (f[i] == 0) {
				sum = max(sum, max(a[i][1], max(a[i][2], a[i][3])));
			}
		}
		ans += sum;
		cout << ans << endl;
		ans = 0;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = 0;
			a[i][1] = 0;
			a[i][2] = 0;
			a[i][3] = 0;
			k[i][1] = 0;
			k[i][2] = 0;
			k[i][3] = 0;
		}
		n = 0;
		b = 0;
	}

	return 0;
}
