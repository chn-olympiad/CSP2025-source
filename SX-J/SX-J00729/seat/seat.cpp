#include <bits/stdc++.h>
#include <cstdio>
using namespace std;



int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, xl[1000], px[100000], b = 1;
	cin >> m >> n;
	int a[n + 5][m + 5];

	int jl;



	for (int i = 1; i <= n * m; i++) {
		cin >> xl[i];
		jl = xl[1];
	}


	for (int i = 100; i >= 0; i--) {

		for (int j = 1; j <= m * n; j++) {
			if (xl[j] == i) {
				px[b] = xl[j];
				b++;
			}

		}
	}



	for (int i = 1; i <= m; i++) {
		if (m % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				a[j][i] = px[i * n - n + j];
			}
		} else {
			for (int j = n; j >= 1; j--) {
				a[j][i] = px[i * n - j + 1];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == jl) {
				cout << j << " " << i << endl;
			}
		}
	}

	return 0;
}

