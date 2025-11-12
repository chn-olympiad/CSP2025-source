#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, q, w;
	cin >> t >> n;
	int a, s, d;
	int z = 0, x = 0, c = 0;
	for (int i = 1; i < t; i++) {
		for (int j = 1; j < t; j++) {
			cin >> a >> s >> d;
			if (a > s && a > d) {
				z += a;
			} else if (s > a && s > d) {
				z += s;
			} else {
				z += d;
			}
		}
	}

	cin >> q;
	for (int p = 1; p < t; p++) {
		for (int o = 1; o < t; o++) {
			cin >> a >> s >> d;
			if (a > s && a > d) {
				x += a;
			} else if (s > a && s > d) {
				x += s;
			} else {
				x += d;
			}
		}
	}
	cin >> w;
	for (int u = 1; u < t; u++) {
		for (int y = 1; y < w; y++) {
			cin >> a >> s >> d;
			if (a > s && a > d || a > s && a > d) {
				c += a;
			} else if (s > a && s < d || s < a && s > d) {
				c += s;
			} else {
				c += d;
			}
		}
	}
	cout << z << endl;
	cout << x / 3 * 2 << endl;
	cout << c - 1;
}
