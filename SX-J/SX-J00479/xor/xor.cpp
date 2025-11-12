#include <bits/stdc++.h>
using namespace std;
int n, k, a[600000], x, sum = 0, y = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (y != 0) {
			x = x ^a[i];
		}
		if (y == 0) {
			x = a[i];
			y++;
		}
		if (x == k || a[i] == k) {
			sum++;
			y = 0;
		}
	}
	cout << sum;
}
