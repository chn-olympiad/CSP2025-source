#include <iostream>
#include <cstdio>
using namespace std;

int n, a[5005], maxn, t;

bool p(int a[], int m) {
	if (m < 3)
		return 0;
	int t = 0, maxn = 0;
	for (int i = 1 ; i <= m ; i++) {
		t += a[i];
		maxn = max(maxn, a[i]);
	}
	if (t > 2 * maxn)
		return true;
	else
		return 0;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		t += a[i];
	}
	if (n < 3 || t <= 2 * maxn) {
		cout << 0;
		return 0;
	}
	if (p(a, n)) {
		cout << 9;
	}

	return 0;
}