#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[10000] = {}, max = 0, sum = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] > 2 * max) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
