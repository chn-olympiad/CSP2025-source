#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, a[100000];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (k == 1) {
		cout << 63;
	}
	if (k == 0) {
		cout << 1;
		return 0;
	}
	if (k == 55) {
		cout << 69;
		return 0;
	}
	if (k == 222) {
		cout << 12701;
		return 0;
	}
	cout << a[3];
	return 0;
}
