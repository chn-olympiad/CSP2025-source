#include <bits/stdc++.h>
using namespace std;


int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, mx = 0;
		cin >> n;
		int a[n][3], ans = 0, gvmt[3] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
				mx = max(mx, a[i][j]);
			}
		}

		ans += mx;

		cout << ans << endl;
	}

	return 0;
}