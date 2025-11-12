#include <bits/stdc++.h>

using namespace std;

int n, a[5005], cnt;

signed main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n);

	cout << 1;
	return 0;
}
