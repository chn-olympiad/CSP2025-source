#include <bits/stdc++.h>
using namespace std;
int n, m, kaa, c, r, kc, a[10000005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	kc = a[1];
	for (int i = 1; i <= n * m; i++) {
		if (a[i] < a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == kc) {
			kaa = i;
			break;
		}
	}
	c = ceil(kaa / n);
	if (c % n != 0) {
		r =  kaa % n;
		if (r == 0) {
			r = m;
		}
	} else {
		r = n + 1 - kaa % n ;
		if (r == 0) {
			r = 1;
		}
	}
	cout << c << ' ' << r;
	//cout << 1 << ' ' << 1;
	return 0;
}