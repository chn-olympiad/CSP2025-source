#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long ans;
long long sum[5005], sum1, mmax = INT_MIN;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] += sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i ; j <= n; j++) {
			sum1 = sum[n] - sum[j] + sum[i];
			for (int y = 0; y <= i; y++) {
				sum1 = sum1 - a[y];
				for (int x = 1; x <= i; x++) {
					mmax = max(mmax, a[x]);
				}
				for (int x = j; x <= n; x++) {
					mmax = max(mmax, a[x]);
				}
				if (sum1 > 2 * mmax and (i - y) + (n - j) >= 3) {
					ans++;
				}
			}
			sum1 = 0;
			mmax = INT_MIN;
		}
	}
	cout << ans / 2 ;
	return 0;
}
