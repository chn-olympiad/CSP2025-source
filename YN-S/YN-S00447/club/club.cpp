#include <bits/stdc++.h>
using namespace std;

int t, n, a[100005][10], b[100005], c[100005], m;
string s;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	while (t--) {
		m = 0;
		cin >> n;
		int s = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
				m += a[i][1];
			}
			if (a[i][2] > a[i][1] && a[i][2] > a[i][3]) {
				m += a[i][2];
			}
			if (a[i][3] > a[i][2] && a[i][3] > a[i][1]) {
				m += a[i][3];
			}
		}
		cout << m;
	}

	return 0;
}