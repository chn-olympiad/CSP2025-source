#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 13;
int n, q, al[maxn];
string a[maxn][2], b[maxn * 3][2];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {

		cin >> a[i][1] >> a[i][2];
	}

	for (int i = 1; i <= q; i++) {

		cin >> b[i][1] >> b[i][2];
	}

	for (int i = 1; i <= q; i++) {

		for (int j = 1; j <= n; j++) {

			if (a[j][1] == b[i][1] && a[j][2] == b[i][2]) {
				al[i] += 2;
			}
		}
	}

	for (int i = 1; i <= q; i++) {

		cout << al[i] << endl;
	}

	return 0;
}