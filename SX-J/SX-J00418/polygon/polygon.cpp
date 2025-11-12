#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[n + 3];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	sort(a + 1, a + n + 1);
	if (n == 3) {
		for (int i = 1; i <= n; i++) {
			sum += a[i];
		}
	}
	if (sum > a[3] * 2) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
