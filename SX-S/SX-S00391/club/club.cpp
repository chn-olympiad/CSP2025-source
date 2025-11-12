#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club,in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int m = 1; m <= t; m++) {
		int a[100022][3] = {0};
		int e[100022] = {0};
		int sum1 = 0;
		int sum2 = 0;
		int sum3 = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			e[i] = max(max(a[i][1], a[i][2]), max(a[i][2], a[i][3]));
		}
		if (n == 2) {
			if (e[1] == a[1][1] && e[2] == a[2][2]) {
				if (e[1] > e[2]) {
					/*อ๊มห*/return 0;
				}
			}
		}
	}
}