#include <bits/stdc++.h>
using namespace std;
int n, a[5000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (n == 3 && a[1] + a[2] + a[3] > a[n] * 2) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
