#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, sum = 1, x;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a;
	for (int i = 2; i <= n * m; i++) {
		cin >> b;
		if (a < b) {
			sum++;
		}
	}
	if ((sum / n) % 2 == 1) {
		x = n - sum % n;
	} else {
		x = sum / n - 1;
	}
	cout << sum / n << " " << x;
	return 0;
}
