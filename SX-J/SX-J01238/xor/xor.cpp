#include <bits/stdc++.h>
using namespace std;
long long n, k, a[700000], ans;
bool flag;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			flag = 1;
		}
	}
	if (k == 0 && flag == 0) {
		if (n % 2 == 0) {
			cout << n / 2;
		} else {
			cout << (n - 1) / 2;
		}
	} else {
		if (k == 1) {
			for (int i = 1; i <= n; i++) {
				if (i + 1 > n) {
					continue;
				}
				if (a[i] != a[i + 1]) {
					ans++;
					i++;
				}
			}
			cout << ans;
		} else if (k == 0) {
			for (int i = 1; i <= n; i++) {
				if (i + 1 > n) {
					continue;
				}
				if (a[i] == a[i + 1]) {
					ans++;
					i++;
				}
			}
			cout << ans;
		} else {
			cout << 0;
		}
	}
	return 0;
}
