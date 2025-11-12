#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int n, k, x, a[N], b[N], c[N], d[N], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	b[1] = a[1];
	for (int i = 2; i <= n; i++) {
		b[i] = b[i - 1] ^ a[i];
	}
	c[n] = a[n];
	for (int i = n - 1; i >= 1; i--) {
		c[i] = c[i + 1] ^ a[i];
	}

	/*for (int i = 1; i <= n; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << c[i] << " ";
	}*/

	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			ans++;
			x = i;
			break;
		}
	}
	for (int i = 2; i < x; i++) {
		if (b[i] == k) {
			ans++;
			break;
		}
	}
	for (int i = n - 1; i > x; i--) {
		if (c[i] == k) {
			ans++;
			break;
		}
	}
	cout << ans;
	return 0;
}