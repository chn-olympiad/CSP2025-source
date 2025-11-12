#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cnt = 1;
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] > a[1]) {
			cnt++;
		}
	}
//	cout << cnt << endl;
//	cout << cnt / m;
	if (cnt % m == 0) {
		int ans = cnt / m;
		cout << ans << " " << m;
	} else if (cnt % m != 0) {
		int ans = cnt / m;
		ans++;
		if (ans % 2 == 0) {
			cout << ans << " ";
			int ans2 = m - cnt % m + 1;
			cout << ans2;
		} else if (ans % 2 != 0) {
			cout << ans << " ";
			int ans2 = cnt % m;
			cout << ans2;
		}
	}
	return 0;
}
