#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[n], i, b[n], d, e, f, g;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (e = 0; e < n - 3; e++) {
		b[0] = a[e];
		for (f = e + 1; f < n - 3; f++) {
			b[1] = a[f];
			for (g = f + 1; g < n - 3; g++) {
				b[2] = a[g];
			}

		}

	}


	return 0;

}