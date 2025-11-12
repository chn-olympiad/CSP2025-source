#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105];
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int sum = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == sum) {
			sum = n * m - i + 1;
			break;
		}
	}
	if (sum > n) {
		if ((sum / n) % 2 == 1) {
			cout << sum / n + 1 << " ";
			cout << n - ((sum - 1) - (sum / n)*m);
		}
		if ((sum / n) % 2 == 0) {
			cout << sum / n + 1 << " ";
			cout << ((sum - 1) - (sum / n)*m) + 1;
		}


	} else {
		cout << 1 << " " << sum;
	}
	return 0;
}
