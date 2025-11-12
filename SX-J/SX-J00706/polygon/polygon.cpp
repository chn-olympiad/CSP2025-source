#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a[55550];
	int n, sum;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (n < 3 || n == 3 && a[1] + a[2] < a[3] || n == 3 && a[1] + a[3] < a[2] || n == 3 && a[3] + a[2] < a[1]) {
			cout << 0;
		}
		if (n == 3 && a[1] + a[2] > a[3] || n == 3 && a[1] + a[3] > a[2] || n == 3 && a[3] + a[2] > a[1]) {
			cout << 1;
		}
	}
	return 0;
}
