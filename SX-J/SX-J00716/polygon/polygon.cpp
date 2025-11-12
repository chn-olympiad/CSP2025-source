#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5555];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	return 0;
}
