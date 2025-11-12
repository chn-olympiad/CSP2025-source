#include <bits/stdc++.h>
using namespace std;
long long n, a[10010], c, s;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (n) {
		c = 0;
		for (int i = 1; i <= n; i++) {
			c += a[i];
			if (c > a[i] * 2) {
				s++;
			}
		}
		n--;
	}
	cout << s;
	return 0;
}