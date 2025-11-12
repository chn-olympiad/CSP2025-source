#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int k, a[500005];
	int n;
	cin >> n >> k;
	bool b = 1, bb = 1;
	int sum = 0, sum2 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			sum++;
		}
		if (a[i] == 0) {
			sum2++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1) {
			b = 0;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1 && a[i] != 0) {
			bb = 0;
			break;
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == 1 && a[i] == a[i + 1]) {
			sum2++;
			i++;
		}
	}
	if (b) {
		cout << n % 2;
		return 0;
	}
	if (bb) {
		if (k) {
			cout << sum;
		} else {
			cout << sum2;
		}
		return 0;
	}
	return 0;
}
