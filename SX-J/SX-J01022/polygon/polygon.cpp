#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	} else if (n == 3) {
		if (a[1] + a[2] + a[3] > max({a[1], a[2], a[3]}))cout << 1;
		else
			cout << 0;
	} else if (n == 4) {
		if (a[1] + a[2] + a[3] > max({a[1], a[2], a[3]}))ans++;
		if (a[1] + a[2] + a[4] > max({a[1], a[2], a[4]}))ans++;
		if (a[1] + a[3] + a[4] > max({a[1], a[3], a[4]}))ans++;
		if (a[2] + a[3] + a[4] > max({a[2], a[3], a[4]}))ans++;
		if (a[1] + a[2] + a[3] + a[4] > max({a[1], a[2], a[3], a[4]}))ans++;
		cout << ans;
	}

	else if (n == 4) {
		if (a[1] + a[2] + a[3] > max({a[1], a[2], a[3]}))ans++;
		if (a[1] + a[2] + a[4] > max({a[1], a[2], a[4]}))ans++;
		if (a[1] + a[2] + a[5] > max({a[1], a[2], a[5]}))ans++;
		if (a[1] + a[3] + a[4] > max({a[1], a[3], a[4]}))ans++;
		if (a[1] + a[3] + a[5] > max({a[1], a[3], a[5]}))ans++;
		if (a[1] + a[4] + a[5] > max({a[1], a[4], a[5]}))ans++;
		if (a[2] + a[3] + a[4] > max({a[2], a[3], a[4]}))ans++;
		if (a[2] + a[3] + a[5] > max({a[2], a[3], a[5]}))ans++;
		if (a[2] + a[4] + a[5] > max({a[2], a[4], a[5]}))ans++;
		if (a[1] + a[2] + a[3] + a[4] > max({a[1], a[2], a[3], a[4]}))ans++;
		if (a[1] + a[2] + a[3] + a[5] > max({a[1], a[2], a[3], a[5]}))ans++;
		if (a[1] + a[3] + a[4] + a[5] > max({a[1], a[3], a[4], a[5]}))ans++;
		if (a[1] + a[2] + a[3] + a[4] + a[5] > max({a[1], a[2], a[3], a[4], a[5]}))ans++;
		cout << ans;
	} else
		cout << 0;
	return 0;
}
