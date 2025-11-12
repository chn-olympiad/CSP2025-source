#include <bits/stdc++.h>
using namespace std;
int n, a[5010], s, ma;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
		ma = max(a[i], ma);
	}
	if (n == 3 && s > (2 * ma)) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}