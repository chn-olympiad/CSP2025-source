#include <bits/stdc++.h>
using namespace std;
int a[10001][10001];
int b1, b2, b3, bn, bm;
int c1, c2, c3, d1, d2, d3, cn, cm;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, a1, a2, a3, ans;
	cin >> t;

	for (int i = 1; i <= t; i++) {

		cin >> n;

		if (n == 2) {
			cin >> a1 >> a2 >> a3;
			cin >> b1 >> b2 >> b3;
			bn = max(a1, max(a2, a3));
			bm = max(b1, max(b2, b3));
			ans = bn + bm;
			cout << ans << endl;
		}

		if (n == 4) {
			cin >> a1 >> a2 >> a3;
			cin >> b1 >> b2 >> b3;
			cin >> c1 >> c2 >> c3;
			cin >> d1 >> d2 >> d3;
			bn = max(a1, max(a2, a3));
			bm = max(b1, max(b2, b3));
			cn = max(c1, max(c2, c3));
			cm = max(d1, max(d2, d3));
			ans = bn + bm + cn + cm;
			cout << ans << endl;
		}
	}

	return 0;
}