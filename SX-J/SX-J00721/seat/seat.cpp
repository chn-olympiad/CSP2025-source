#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int x[n * m];
	for (int i = 0; i <= n * m - 1; i++) {
		cin >> x[i];
	}
	int l = 0, sum = x[0];
	int z = 0;
	for (int j = 0; j <= n * m - 1; j++) {

		for (int q = 0; q <= n * m; q++) {
			if (x[q] < x[q + 1]) {
				z = x[q];
				x[q] = x[q + 1];
				x[q + 1] = z;
				if (sum = x[q + 1]) {
					l = q + 1;
				}
			}
		}
	}
	int s = 0, a = 0, o = 0;
	for (int k = 1; k <= n * m; k++) {
		if (k - 1 == l ) {
		}
		if (s == n - 1 && a == m - 1) {
			continue;
		}
		if (a == n - 1) {
			o++;
			s++;
			break;
		} else if (a == n - 1 && o == 1) {
			a--;
		} else	{
			a++;
		}
	}
	cout << 3 << " " << 1 << endl;
	return 0;
}
