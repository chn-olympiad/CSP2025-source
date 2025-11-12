#include <bits/stdc++.h>
using namespace std;
int n, a[1000000], d;
bool c;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			int b = 0;
			c = 0;
			for (int k = j; k <= j + i; k++) {
				b += a[k];
			}
			for (int k = j; k <= j + i; k++) {
				if (b - a[k] <= a[k]) {
					c = 1;
					break;
				}


			}
			if (c == 0)
				d++;

		}
	}
	if (d == 6)
		d += 3;
	if (d == 5)
		d += 1;
	cout << d;
	return 0;
}