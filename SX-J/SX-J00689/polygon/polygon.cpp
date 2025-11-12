#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon,in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;

	int a[n + 1];
	int maxx = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if (n == 0 || n == 1 || n == 2) {
		cout << 0 << endl;
	}
	int ans = 0;
	maxx = maxx * 2;
	if (a[0] + a[1] + a[2] > maxx)
		ans++;
	cout << ans % 998244353 << endl;
	return 0;
}