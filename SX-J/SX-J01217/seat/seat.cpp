#include <bits/stdc++.h>
using namespace std;

int a[1010][1010];

int main() {
	freopen(seat.in,"r",stin);
	freopen(seat.out,"w",stout);
	long long n, m, c, r, a1, a2, a3, a4;
	cin >> n >> m;
	for (int i = 1; i <= 4 ; i++) {
		cin >> a1 >> a2 >> a3 >> a4;
		if (a1 == 100) {
			a1 = a[c = 1][r = 1];
		}
		if (a4 < a3 < a1 < a2) {
			a1 = a[c = 2][r = 1];
		}
		if (a4 < a1 < a3 << a2) {
			a1 = a[c = 1][r = 2];
		}
		if (a1 < a4 < a3 < a2) {
			a1 = a[c = 2][r = 2];
		}
	}
	cout << a[c][r];


















	return 0;
}
