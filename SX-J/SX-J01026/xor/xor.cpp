#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, op = 0, io = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			op = 1;
		if ((a[i] != 1) && (a[i] != 0))
			io = 1;
	}
	if (op == 0)
		cout << n / 2;
	else if (io == 0) {
		int ans = 0;
		if (k == 1) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1)
					ans++;
			}
		} else if (k == 0) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0)
					ans++;
				else if ((a[i] == 1) && (i != 1) && (a[i - 1] == 1)) {
					ans++;
					a[i] = -1;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
