#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int zc = n * m;
	int x = 0;
	for (int i = 1; i <= zc; i++) {
		cin >> a[i];
	}
	x = a[1];
	int cc = 0;
	sort(a + 1, a + zc + 1, cmp);
	for (int i = 1; i <= zc; i++) {
		if (x == a[i]) {
			cc = i;
			break;
		}
	}
	int h, l;
	int xx = cc % n;
	int yy = cc / n;
	if (xx == 0) {
		l = cc / n;
		if (yy % 2 == 0) {
			h = 1;
		} else {
			h = n;
		}
	} else {
		l = yy + 1;
		if (l % 2 == 0) {
			h = n - xx + 1;
		} else
			h = xx;
	}
	cout << l << " " << h << endl;
	return 0;
}
