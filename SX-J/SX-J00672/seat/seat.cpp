#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m + 1];
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int ans = 1;
	for (int i = 2; i <= n * m; i++) {
		if (a[i] > a[1]) {
			ans++;
		}
	}
	int num = ans % n, sum = ans / n;
	if (num == 0) {
		if (sum % 2 == 1) {
			cout << sum << " " << n ;
		} else {
			cout << sum << " " << 1 ;
		}
	} else {
		if (sum % 2 == 1) {
			cout << sum + 1 << " " << n - num + 1 ;
		} else {
			cout << sum + 1 << " " << num ;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}