#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], xiao, place, c, r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	xiao = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == xiao) {
			place = i;
			break;
		}
	}
	if (place % n == 0) {
		c = place / n;
		if (c % 2 == 1) {
			r = n;
		} else {
			r = 1;
		}

	} else {
		c = place / n + 1;
		if (c % 2 == 1) {
			r = place % n;
		} else {
			r = n - place % n + 1;
		}
	}
	cout << c << " " << r ;
	return 0;
}
