#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], b[105];
int lie, hang;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int zs = n * m;
	for (int i = 0; i < zs; i++) {
		cin >> a[i];
	}
	int r = a[0];
	int fu = 0;
	for (int i = 0; i < zs; i++) {
		for (int j = 0; j < zs - 1; j++) {
			if (a[j] < a[j + 1]) {
				fu = a[j];
				a[j] = a[j + 1];
				a[j + 1] = fu;
			}
		}
	}
	int xr = 0;
	for (int i = 0; i < zs; i++) {
		if (a[i] == r) {
			xr = i;
		}
	}
	xr += 1;
	if (xr == 1) {
		cout << 1 << ' ' << 1;
	} else {
		int k = 1;
		if ((n * k) < xr) {
			k++;
		} else if ((n * k) == xr) {
			lie = k;
			hang = n;
		} else if ((n * k) > xr) {
			lie = k;
			hang = xr - (n *k);
		}
	}




	return 0;
}