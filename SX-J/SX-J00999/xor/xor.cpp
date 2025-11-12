#include <bits/stdc++.h>
using namespace std;
long long n, k, a[5 * 100000 + 5], sum, cnt, mmax, s;

signed main(void) {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (long long i = 1; i <= n; ++i)
		cin >> a[i];
	s++;
	for (long long i = 1, j = i; i <= n && j <= n;) {
		sum = 0;
		for (long long l = i; l <= j; ++l) {
			sum = sum ^a[l];
			if (sum == k) {
				cnt++;
				i = l + 1;
				j = i;
				sum = 0;
			} else {
				j++;
			}
			mmax = max(mmax, cnt);
			if (i > n) {
				break;
			}
		}
	}
	cout << mmax;
	return 0;
}
