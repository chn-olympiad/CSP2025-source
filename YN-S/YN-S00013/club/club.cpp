#include <bits/stdc++.h>
using namespace std;
int n, a, b = 0, t = 0, g = 0;
int x[10001], y[10001], z[10001];
int xx[10001], yy[10001], zz[10001];
int l[100001], l1  [10001];

void s(int x1, int y1, int z1) {
	int m;
	for (int i = 0; i < a; i++) {
		if (x[i] > y[i] && x[i] > z[i]) {
			m = x[i];
			x1 += 1;
		} else if (y[i] > x[i] && y[i] > z[i]) {
			m = y[i];
			y1 += 1;
		} else {
			m = z[i];
			z1 += 1;
		}
		b += m;
	}
	if (x1 <= a / 2 && y1 <= a / 2 && z1 <= a / 2) {
		return ;
	} else {
		if (x1 > a / 2) {
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < a; j++) {

				}
			}
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		b = 0;
		cin >> a;
		for (int i = 0; i < a; i++) {
			cin >> x[i] >> y[i] >> z[i];
			xx[i] = i;
			yy[i] = i;
			zz[i] = i;
		}
		s(0, 0, 0);
		cout << b;
	}
	return 0;
}