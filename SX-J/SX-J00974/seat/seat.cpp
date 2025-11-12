#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R;
	cin >> n >> m;
	int CSP[n * m + 5], seat = 1;
	for (int i = 0; i < n * m; i++) {
		cin >> CSP[i];
		R = CSP[0];
		if (CSP[i] > R)
			seat++ ;
	}
	int D = 0;
	for (int i = 1; i <= m; i++) {
		if (seat >= D && seat <= i * n) {
			if (i % 2 == 0) {
				cout << i << " " << 2 * n - seat + 1;
			} else {
				cout << i << " " << seat % n;
			}
			break;
		}
		D += n;
	}
	return 0;
}
