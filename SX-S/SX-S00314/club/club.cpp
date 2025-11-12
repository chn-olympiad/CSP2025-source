#include <bits/stdc++.h>
using namespace std;
int t, n, ans = 0;

int a[3];



int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[1] >> a[2] >> a[3];
			int maxx = 0;
			if (a[1] > a[2]) {
				maxx = a[1];
			} else {
				maxx = a[2];
			}
			if (a[3] > maxx) {
				maxx = a[3];
			}

			ans += maxx;


		}
		cout << ans;
		ans = 0;

	}

	return 0;
}
