#include <bits/stdc++.h>
using namespace std;
vector<int> b;
int c, n, m,  l, i, g, f;
int a[100][100];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> n >> m;
	for (int q = 1; q <= m * n; q++) {
		cin >> c;
		b[q] = c;
	}
	l = 1;
	f = 1;
	int s = 1;
	for (int q = 1; q <= m * n; q++) {
		if (b[1] < b[q + 1]) {
			l = q + 1;
		}
	}
	for (int z = 1;; z++) {
		for (int x = 1; x <= n; ++x, ++f) {
			a[s][n] = f;
			if (f == l) {
				cout << s << n;
				return 0;
			}
		}
		s = s + 1;
		for (int v = n; v >= 1; v--, ++f) {
			a[s][v] = f;
			if (f == l) {
				cout << s << v;
				return 0;
			}
		}
		s = s + 1;
	}

	return 0;
}
