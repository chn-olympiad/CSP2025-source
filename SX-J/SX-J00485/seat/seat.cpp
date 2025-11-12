#include <bits/stdc++.h>
using namespace std;
int n, m, num = 0;
long long a[1010];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
		if (a[1] < a[i]) {
			num++;
		}
	}
	num++;
	cout << ceil(num * 1.0 / n) << " ";
	if (int(ceil(num * 1.0 / n)) % 2 == 0) {
		cout << n - num % n  + 1;
	} else {
		if (num % n == 0) {
			cout << n;
		} else {
			cout << num % n ;
		}

	}
	return 0;
}
