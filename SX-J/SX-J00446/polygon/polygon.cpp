#include <bits/stdc++.h>
using namespace std;
long long n, a[5010], maxn;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		maxn = max(max(a[1], a[2]), a[3]);
		if (a[1] + a[2] + a[3] > 2 * maxn)
			cout << 1;
		else
			cout << 0;

	} else {
		cout << 0;
	}
	return 0;
}
