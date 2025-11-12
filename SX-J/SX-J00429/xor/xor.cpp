#include <bits/stdc++.h>
using namespace std;
long long a[100005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	long long sum = 0, sum2 = 0;
	int b = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			sum++;
		}
		if (a[i] == 1 && a[i - 1] == 1 && b == 0) {
			sum2++;
			b = 1;
		} else {
			b = 0;
		}
	}
	if (n == 1 && k == 0) {
		if (a[1] == 0) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if (n == 2 && k == 0) {
		if (a[1] == 0 && a[2] == 0) {
			cout << 2;
		} else if (a[1] == a[2]) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if (k == 0 && sum == n) {
		cout << n / 2;
	} else if (k == 0) {
		cout << n - sum + sum2;
	} else if (k == 1) {
		cout << sum;
	}
	return 0;
}
