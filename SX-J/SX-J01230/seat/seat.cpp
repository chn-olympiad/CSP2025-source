#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, l, yy, s = 0;
int a[10005];

bool cmp(int p, int q) {
	return p > q;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int b = n * m;
	for (int i = 1; i <= b; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + 1 + b, cmp);
	for (int i = 1; i <= b; i++) {
		if (a[i] == x) {
			y = i;
			break;
		}
	}
	yy = y;
	if (y <= n) {
		l = 1;
	} else {
		for (int i = 1; ; i++) {
			if (yy < n) {
				l = s + 1;
				break;
			}
			yy = yy - n;
			s++;
		}
	}
	cout << l << " ";
	if (l == 1) {
		cout << y;
		return 0;
	} else {
		if (l % 2 == 0) {
			cout << 1 + (y - ((l - 1)*n));
		} else
			cout << y - ((l - 1)*n);
	}
	return 0;
}
