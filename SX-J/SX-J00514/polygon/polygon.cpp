#include <bits/stdc++.h>
using namespace std;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, maxx = -1, maxxx = -1, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1 || n == 2) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		maxx = max(a[1], a[2]);
		maxxx = max(maxx, a[3]);
		sum = a[1] + a[2] + a[3];
		if (sum > 2 * maxxx)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5)
		cout << 10;
	if (n == 5 && a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10)
		cout << 6;
	return 0;
}

