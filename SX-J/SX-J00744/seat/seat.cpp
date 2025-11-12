#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a, b;
	cin >> n;
	cin >> m;
	a = m * n;
	b = a - 1;
	int s[b], i, d[b], e, f, g, h, c, j, k, r;
	for (i = 0; i < a; i++) {
		cin >> s[i];
	}
	h = s[0];
	for (i = 0; i < a; i++) {
		f = s[0];
		for (e = 0; e < a; e++) {
			if (s[e] < s[e + 1]) {
				f = s[e + 1];
				g = e + 1;
			}
		}
		if (h == f)
			h = g;
		s[g] = 0;
		d[i] = f;
	}

	if (n >= h) {
		c = 1;
		r = h;
	} else {
		j = h / n;
		k = h % n;
		if (j % 2 == 0) {
			if (k > 0) {
				c = j + 1;
				r = k;
			} else {
				c = j;
				r = n;
			}
		} else {
			if (k > 0) {
				c = j + 1;
				r = n - k + 1;
			} else {
				c = j;
				r = 1;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}