#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 5 + 10;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, s = 0, x = 0, maxx = LLONG_MIN;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		if (a[1] == k) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if (n == 2) {
		if (a[1] == k) {
			s++;
		}
		if (a[2] == k) {
			s++;
		}
		if (a[1]^a[2] == k) {
			x++;
		}
		cout << max(x, s);
	} else {
		cout << n;
	}
	return 0;
}
