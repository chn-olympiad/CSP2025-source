#include <bits/stdc++.h>
using namespace std;
long long n, a[5000005], mx = 0, sum = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	if (sum > 2 * mx)
		cout << 1;
	else
		cout << 0;
	return 0;
}
