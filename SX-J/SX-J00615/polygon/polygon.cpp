#include <bits/stdc++.h>
using namespace std;
//long long n,a[5005],dp[5005][5005],s[5005],maxi[5005];
long long n, a[5005], sum, p = 1, q = 1, s, maxi;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		s = a[1] + a[2] + a[3];
		maxi = max(max(a[1], a[2]), a[3]);
		if (s > 2 * maxi)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		p = 1;
		q = 1;
		for (int k = n; k >= n - i + 1; k--) {
			p *= k;
			p %= 998244353;
		}
		for (int k = 1; k <= i; k++) {
			q *= k;
			q %= 998244353;
		}
		sum += p / q;
		sum = sum % 998244353;
	}
	sum = sum % 998244353;
	cout << sum;
	return 0;
}