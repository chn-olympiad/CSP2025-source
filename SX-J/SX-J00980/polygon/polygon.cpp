#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
	} else if (n == 3) {
		for (int i = 0; i < n; i++) {
			if (x < a[i]) {
				x = a[i];
			}
		}
		if (x * 2 < (a[0] + a[1] + a[2] - x)) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << n + 1;
	}
	return 0;
}
