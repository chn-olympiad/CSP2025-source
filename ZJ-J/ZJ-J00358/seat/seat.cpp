#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 100;
int n, m, a[N], t, zb;
int cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			zb = i;
			break;
		}
	}
	int tt = zb / n;
	if (zb % n != 0) {
		tt ++;
	}
	cout << tt << " ";
	if (tt % 2 == 1) {
		if (zb % n == 0) {
			cout << n;
		}
		else {
			cout << zb % n;
		}
	}
	else {
		if (zb % n == 0) {
			cout << 1;
		}
		else {
			cout << n - zb % n + 1;
		}
	}
	return 0;
}
