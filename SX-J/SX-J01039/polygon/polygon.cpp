#include <bits/stdc++.h>
using namespace std;
int n, z;
int q, w, e, r, t;
int a[5005];
int MAX;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i > MAX]) {
			MAX = a[i];
		}
	}
	if (MAX == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		q = i;
		w = q + 1;
		e = w + 1;
		while (n) {
			if ((a[q] + a[w] + a[e]) > (2 * max(a[q], max(a[w], a[e])) ) ) {
				z++;
			}
			e++;
			if (e > n) {
				w++;
				if (w > n - 1) {
					q++;
					if (q > n - 2) {
						break;
					}
					w = q + 1;
					e = w + 1;
				}
				e = w + 1;
			}
		}

	}
	cout << (z + 2) % 998244353;
	return 0;
}