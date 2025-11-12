#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	int g, x, y, p = 0, d = 0;
	char z[10000000], c[10];
	char a[10000000];
	cin >> a[y];
	for (int i = 0; i < 1E6; i++) {
		if (a[i] == c[1]) {
			break;
		}
		d++;
		if (a[i] >= 10) {
			p++;
		}
	}

	for (int i = 0; i < 1E6; i++) {
		x = 0;
		g = 1;
		for (int w = 1; w <= d; w++) {
			if (a[i] < a[w])
				g++;
			if (a[i] == a[w])
				x++;
		}
		z[g] = a[i];
		if (x != 1) {
			for (int q = 1; q < x; q++) {
				g++;
				z[g] = a[i];
			}

		}
	}
	for (int e = 0; e <= d; e++) {
		cout << z[e + p];
	}
	return 0;
}