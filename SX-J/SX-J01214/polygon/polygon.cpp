#include <bits/stdc++.h>
using namespace std;
int a[10010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long sum = 0;
	for (int i = 3; i <= n; i++) {
		long long ans = 1, j, num = 1;
		for (j = 1; j <= i; j++) {
			ans *= j;
		}
		for (long long t = n; t >= j; t--) {
			num *= t;
		}
		sum = (sum + num / ans) % 998244353;
	}
	cout << sum;
	return 0;
}
