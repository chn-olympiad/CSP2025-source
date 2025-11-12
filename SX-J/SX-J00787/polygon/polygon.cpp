#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0, a[10];
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i <= n; i++) {
		if (n > a[i]) {
			if (sum >= n * 2) {
				cout << sum;
			}
		}
	}
	return 0;
}
