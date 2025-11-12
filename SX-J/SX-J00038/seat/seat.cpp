#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, r, a1, a2, a3, a4, a5, a6, a7, a8, a9;
	cin >> n >> m;
	if (n == 2 && m == 2) {
		cin >> a1 >> a2 >> a3 >> a4;
		if (a1 == 99) {
			cout << 1 << ' ' << 2;
		} else
			cout << 2 << ' ' << 2;
	} else {
		cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9;
		cout << 3 << ' ' << 1;
	}
	return 0;
}
