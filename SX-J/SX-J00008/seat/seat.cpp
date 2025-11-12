#include <bits/stdc++.h>
using namespace std;
int a, s, f[105], g, h, l, k, p;

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	cin >> a >> s;
	int d[a][s];
	for (int i = 0; i <= a * s - 1; i++) {
		cin >> f[i];
		h++;
	}
	l = f[0];
	for (int i = 0; i <= a * s - 1; i++) {
		for (int j = 0; j <= a * s - 1; j++) {
			if (f[j] < f[j + 1]) {
				g = f[j];
				f[j] = f[j + 1];
				f[j + 1] = g;
			}
		}
	}
	for (int i = 0; i <= a - 1; i++) {
		for (int j = 0; j <= s - 1; j++) {
			d[i][j] = f[k];
			k++;
		}
	}
	for (int i = 0; i <= a * s - 1; i++) {
		if (f[i] = l) {
			p = i + 1;
			break;
		}
	}
	if (p >= s)
		p = p % s + 1;
	for (int i = 0; i <= a - 1; i++) {
		for (int j = 0; j <= s - 1; j++) {
			if (d[i][j] == l) {
				cout << i + 1 << " " << j  + p;
				return 0;
			}
		}
	}
	return 0;
}
