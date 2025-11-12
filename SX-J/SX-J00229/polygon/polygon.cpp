#include <bits/stdc++.h>
using namespace std;
int n, ans, a[1000];

int main() {
	cin >> n;
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (a[1] + a[2] + a[3] > a[3] * 2) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
