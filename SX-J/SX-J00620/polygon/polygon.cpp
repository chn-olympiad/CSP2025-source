#include <bits/stdc++.h>
using namespace std;
long long sum, n;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (long long i = 3; i <= n; i++) {
		long long num1 = 1, num2 = 1;
		for (long long j = i; j >= 1; j--) {
			if (num1 * (n - i + j) > 0) {
				num1 *= (n - i + j);
			} else {
				num2 *= (n - i + j);
			}
		}
		for (long long j = i; j >= 1; j--) {
			if (num1 % j == 0) {
				num1 /= j;
			} else {
				num2 /= j;
			}
		}
		sum += num1;
		sum %= 998244353;
	}
	cout << sum;
	return 0;
}