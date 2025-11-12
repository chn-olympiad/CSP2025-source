#include <bits/stdc++.h>
using namespace std;
long long n, a[10005], y = 0, e = 0, s = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", n);
	int c, h, f;
	for (int i = 1; i <= n; i += 3) {
		cin >> a[i] >> a[i + 1] >> a[i + 2];
		if (a[i] > a[i + 1]) {
			c += 1;
			if (c <= n / 2) {
				y += a[i];
			} else {
				c -= 1;
			}
		} else if (a[i + 1] > a[i + 2]) {
			h += 1;
			if (h <= n / 2) {
				e += a[i + 1];
			} else {
				h -= 1;
			}
		} else {
			f += 1;
			if (f <= n / 2) {
				s += a[i + 2];
			} else {
				f -= 1;
			}
		}

	}
	cout << y << endl << e << endl << s << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}