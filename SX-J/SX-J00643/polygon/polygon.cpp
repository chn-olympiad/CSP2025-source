#include <bits/stdc++.h>
using namespace std;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 0) {
		cout << 0;
		return 0;
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n == 2) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		cout << 1;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		ans += (1 + i) * i / 2;
	}
	cout << ans;
	return 0;
}
