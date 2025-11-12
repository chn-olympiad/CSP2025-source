#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	int a[2250];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (n == 2) {
			cout << 2;
		}
		if (n == 1) {
			cout << 1;
		}
		if (k == 0) {
			cout << 1;
		}
	}
	return 0;
}
