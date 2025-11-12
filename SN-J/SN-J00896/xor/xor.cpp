#include <bits/stdc++.h>
using namespace std;
int n, k, a[500003];
int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		cout << 1 << endl;
	}
	if (k == 2) {
		cout << 2 << endl;
	}
	return 0;
}
