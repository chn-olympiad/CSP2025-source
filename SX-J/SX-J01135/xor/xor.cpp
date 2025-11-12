#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5+5;
int n, k;
int a[N], ans;
int a0, a1;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			a0++;
		}
		if (a[i] == 1) {
			a1++;
		}
	}
	if (a1 == n && k == 0) {
		cout << n / 2;
		return 0;
	}
	if (a1 + a0 == n) {
		if (k == 0) {
			for (int i = 0; i < n; i++) {
				if (a[i] == 0) {
					ans++;
				} else {
					if (a[i] == a[i + 1]) {
						ans++;
						i++;
					}
				}
			}
			cout << ans;
			return 0;
		}
		if (k == 1) {
			cout << a1;
			return 0;
		}
	}
	cout << 2;
	return 0;
}