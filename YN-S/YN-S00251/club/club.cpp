#include <bits/stdc++.h>
using namespace std;
int t, n;
int z[10001][20001];
int maxn[100001], c[5];
int ans, c1, c2, c3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t != 0) {
		t--;
		ans = 0;
		cin >> n;

		for (int i = 1; i <= n; i++) {

			maxn[i] = -1;
		}

		for (int i = 1; i <= 3; i++) {

			c[i] = 0;
		}

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				cin >> z[i][j];

				if (z[i][j] > maxn[i]) {
					maxn[i] = z[i][j];
				}
			}
		}

		for (int i = 1; i <= n; i++) {

			ans += maxn[i];
		}

		cout << ans << endl;
	}

	return 0;
}
/*
4 2 1
3 2 4
5 3 4
3 5 1
*/