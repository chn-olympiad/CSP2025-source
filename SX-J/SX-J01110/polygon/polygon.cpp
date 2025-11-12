#include <bits/stdc++.h>
using namespace std;
long long a, b, c, n, ma = 0, d;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n == 3) {
		cin >> a;
		ma == max(a, ma);
		d += a;
		cin >> b;
		d += b;
		ma == max(b, ma);
		cin >> c;
		d += c;
		ma == max(c, ma);
		if ((d / ma) > 2) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	cout << n - 2;
	return 0;
}
