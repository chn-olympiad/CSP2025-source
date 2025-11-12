#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int l = a[1];
	sort(a + 1, a + n * m + 1);
	int ans = 0;
	for (int i = 1; i <= n * m; i++) {
		b[n * m - i + 1] = a[i];
	}
	for (int i = 1; i <= n * m; i++) {
		if (b[i] == l) {
			ans = i;
			break;
		}
	}
	int k = 0;
	if (ans % n != 0) {
		cout << ans / n + 1;
		k = ans / n + 1;
	} else {
		cout << ans / n << " "  << n; 
		return 0;
	}
	cout << " ";
	if (k % 2 == 0) {
		cout << n -(ans % n) + 1;
	} else {
		cout << ans % n;
	}
	return 0;
}
