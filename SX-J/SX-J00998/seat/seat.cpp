#include <bits/stdc++.h>
using namespace std;
int n, m, i, d, f;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m ;
	i = n * m;
	cin >> f;
	d = f;
	for (int q = 1; q <= i; q++) {
		int w = 1, r = 1;
		cin >> f;
		if (d < f) {
			r = r + 1;
			w = w + 1;
		} else if (w % 2 == 1) {
			r = r + 1;
			w = w + 1;
		}
		if (d > f) {
			cout << w << " " << r;
			return 0;
		}
	}
	return 0;
}
