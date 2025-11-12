#include <bits/stdc++.h>
using namespace std;
int n, m, cj[10005], b, xr;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n + m; i++) {
		cin >> cj[i];
		if (i == 1) {
			xr = cj[i];
		}
	}
	for (int i = 1; i <= n + m; i++) {
		for (int j = 1; j <= i; j++) {
			if (cj[j] < cj[i]) {
				b = cj[i];
				cj[i] = cj[j];
				cj[j] = b;
			}
		}
	}
	for (int i = 1; i <= n + m; i++) {
		if (xr == cj[i]) {
			if (n % (i / m) == 0) {

			}
		}
	}
}
