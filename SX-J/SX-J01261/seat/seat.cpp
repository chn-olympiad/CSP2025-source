#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, rc, q, h;
	cin >> n >> m;
	int a[n * m];
	cin >> rc;
	a[0] = rc;
	for (int i = 1; i < n * m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n * m; i++) {
		q = a[i];
		h = a[i + 1];
		if (q >= h) {
			a[i] = q;
		} else {
			a[i] = h;
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (a[i] == rc) {
			if ((i + 1) % n == 0) {
				cout << (i + 1) % m << " " << n;
				break;
			} else if ((i + 1) % m == 0) {
				cout << m << " " << (i + 1) % n;
				break;
			} else {
				cout << (i + 1) % m¡¡ << " " << (i + 1) % n;
				break;
			}
		}
	}
	return 0;
}