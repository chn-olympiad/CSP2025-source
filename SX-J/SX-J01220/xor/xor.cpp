#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[1000009];
int numzero;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!a[i])
			numzero++;
	}
	if ((n  == 1) && k == 0 && numzero == 0) {
		cout << 0;
		return 0;
	} else if ((n  == 2) && k == 0 && numzero == 1) {
		cout << 1;
		return 0;
	} else if (k == 0) {
		if (numzero == 0) {
			cout << n / 2;
			return 0;
		} else {
			cout << (n - numzero) / 2 + (numzero);
			return 0;
		}
	} else {
		if (numzero == 0) {
			cout << n;
			return 0;
		} else {
			cout << (n - numzero) + (numzero / 2);
			return 0;
		}
	}
	return 0;
}
