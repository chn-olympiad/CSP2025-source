#include <bits/stdc++.h>
using namespace std;
long long n, m, z, x;
const int N = 1e5+10;
int a[N], t;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	z = n * m;
	for (int i = 0; i < z; i++) {
		cin >> a[i];
	}
	t = a[0] + 0;
	sort(a, a + z);
	for (int i = z - 1; i >= 0; i--) {
		if (a[i] == t) {
			x = z - i ;
		}
	}
	if (x % n > 0) {
		if (x / n % 2 == 1) {
			cout << x / n + 1 << ' ' << n - x % n + 1;
		} else {
			cout << x / n + 1 << ' ' << x % n;
		}
	} else {
		if (x / n % 2 == 1) {
			cout << x / n << ' ' << n;
		} else {
			cout << x / n << ' ' << 1;
		}
	}

	return 0;
}