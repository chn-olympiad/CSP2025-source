#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], b = 0, c;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	cin >> b;

	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (b == k) {
			c++;
			b = a[i];
			continue;
		}

		b = b ^a[i];
		if ((i == n - 1)  && b == k) {
			c++;
		}
	}
	cout << c;
	return 0;
}