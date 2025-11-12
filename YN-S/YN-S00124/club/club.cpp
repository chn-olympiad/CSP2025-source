#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][3];
int d[N][3];
int n;
int ans;
int t;

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		cin >> n;
		int k = n / 2;

		for (int i = 1; i <= n; i++) {

			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}

		d[0][0] = 1;

		for (int i = 1; i <= n; i++) {

			for (int j = k; j >= 1; j--) {

				d[i][j] = max(d[i - 1][j], d[i][j--] + a[i][j]);
			}
		}

		for (int i = 1; i <= n; i++) {

			for (int j = k; j >= 1; j--) {

				ans += d[i][j];
			}
		}

		cout << ans << endl;
	}

	return 0;
}

