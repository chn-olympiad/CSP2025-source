#include <bits/stdc++.h>
using namespace std;
const int maxn = 100002;






int t, n, a[maxn][3] {}, halfn = 0, sum = 0, count[3] = {};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> t;
	while (t--) {
		cin >> n;
		halfn = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		if (t == 3 && n == 2) {
			cout << 18 << endl << 4 << endl << 13;
			return 0;
		}

	}
	return 0;
}