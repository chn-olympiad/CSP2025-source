#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000], i, j, a1, xx, t;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (i = 1; i <= n * m; i++) {

		cin >> a[i];
		if (i == 1) {
			a1 = a[i];
		}
	}
	sort(a + 1, a + (n *m) + 1);
	for (i = 1; i <= n * m; i++) {
		if (a[i] == a1) {
			xx = (n *m) + 1 - i;
		}
	}
	if (xx % m != 0) {
		t = (xx / m) + 1;
		cout << t << " ";
	} else {
		t = (xx / m);
		cout << t << " ";
	}
	if (t == 1) {
		cout << xx;
	} else if (t % 2 != 0) {
		cout << xx % m;
	} else {
		cout << m + 1 - (xx % m);
	}
	return 0;
}
