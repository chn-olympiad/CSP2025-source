#include <bits/stdc++.h>
using namespace std;
int n, a[50010], k, c;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c += a[i];
		if (c % 998 >= 3 || c % 244 >= 3 || c % 353 >= 3) {
			k++;
		}
	}
	cout << k * 2 + 1;
	return 0;
}
