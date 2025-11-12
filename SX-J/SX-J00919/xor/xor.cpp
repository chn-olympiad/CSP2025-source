#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, mmax = INT_MIN;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		long long sum = 0;
		for (int j = i; j < k; j++) {
			sum += a[j] ^ a[j - 1];
		}
		mmax = max(mmax, sum);
	}
	cout << mmax;

	return 0;
}