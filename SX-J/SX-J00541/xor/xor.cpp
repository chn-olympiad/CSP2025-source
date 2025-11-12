#include <bits/stdc++.h>

using namespace std;

int n, k;

int a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (k == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 1) {
				ans ++;
			}
		}
		cout << ans;
		return 0;
	}
	if (k == 0) {
		int sum = 0;
		bool q = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 0) {
				q = 0;
				sum ++;
			} else {
				if (q == 0) {
					q = 1;
				} else {
					sum ++;
					q = 0;
				}
			}
		}
		cout << sum;
		return 0;
	}
	return 0;
}
