#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[105];

bool cmp(int xx, int yy) {
	return xx > yy;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, rcj, bh;
	cin >> n >> m;
	int t = n * m;
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
		if (i == 1)
			rcj = a[i];
	}
	sort(a + 1, a + 1 + t, cmp);
	for (int i = 1; i <= t; i++) {
		if (a[i] == rcj) {
			bh = i;
		}
	}
	int l = bh / n + 1;
	int h;
	if (bh % n == 0) {
		cout << bh / n << ' ';
		if ((bh / n) % 2 == 0) {
			cout << 1;
		} else {
			cout << n;
		}
		return 0;
	} else if (l % 2 == 0) {
		h = n - (bh % n - 1);
	} else {
		h = 1 + (bh % n - 1);
	}
	cout << l << " " << h;
	return 0;
}
