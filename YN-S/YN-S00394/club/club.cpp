#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);

	int t, n, a[2000];
	int c[2000];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		int b = 0, h = 0;
		for (int j = 1; j <= t; j++) {
			cin >> a[j];
			if (a[j] > b) {
				b = a[j];
			}
			h = h + b;
		}
		c[i] = h;
	}
	for (int i = 1; i <= n; i++) {
		cout << c[i] << endl;
	}
	return 0;

}