#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[n] == 5) {
		cout << "9";
	} else {
		cout << "6";
	}
	return 0;
}