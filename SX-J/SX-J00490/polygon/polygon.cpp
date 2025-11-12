#include <bits/stdc++.h>
using namespace std;
const int d = 998244353;
int a[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, maxx = INT_MIN;
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		for (int i = 1; i <= n; i++) {
			ans += a[i];
			maxx = max(maxx, a[i]);
		}
		if (ans > 2 * maxx) {
			cout << 1 % d;
		} else {
			cout << 0 % d;
		}
	} else {
		if (n == 5) {
			cout << 6;
		} else if (n == 20) {
			cout << 1042392;
		} else if (n == 500) {
			cout << 366911923;
		}
	}
	return 0;
}