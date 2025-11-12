#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum = 0, mmax = INT_MIN, cnt;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int p = i; p <= j; p++) {
				sum = sum | a[p];
				if (sum == k) {
					mmax = max(mmax, abs(j - i) + 1 );
				}
			}
			sum = cnt = 0;
		}

	}
	cout << mmax / 2;
	return 0;
}
