#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long n, z, m;
int a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		z += a[i];
		m = max(a[i], a[i + 1]);
	}
	if (z > 2 * m) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}