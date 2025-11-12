#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, bz, f = 0, di = 0;
const int maxn = 1e5 + 13;
int a[3][maxn], ba[maxn];
//bool e1[maxn], e2[maxn], e3[maxn];, c1 = 0, c2 = 0, c3 = 0, al = 0
/*
void px1() {
	for (int k = 1; k <= n; k++) {

		for (int i = 1; i <= n; i++) {

			for (int j = i; j <= n; j++) {

				if (a[k][j] >= a[k][i]) {
					int d = a[k][j];
					a[k][j] = a[k][i];
					a[k][i] = d;
				}
			}
		}
	}
}

void px2() {
	for (int i = 1; i <= f; i++) {

		for (int j = i; j <= f; j++) {

			if (ba[j] >= ba[i]) {
				int d = ba[j];
				ba[j] = ba[i];
				ba[i] = d;
			}
		}px2();
	}px1();


		for (int i = 1; i <= 3; i++) {

			for (int j = 1; j <= bz; j++) {

				f++;
				ba[f] = a[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {

			e += ba[i];
		}


}
*/
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		cin >> n;
		bz = n / 2;

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				cin >> a[j][i];
				di += a[j][i];
			}
		}

		cout << di / 2 << endl;
	}

	return 0;
}