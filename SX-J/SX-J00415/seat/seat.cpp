#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[100500], kk, ans1, ans2;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	kk = a[1];
	sort(a + 1, a + n *m + 1);
	for (k = 1; k <= n * m; k++) {
		if (a[k] == kk) {
			break;
		}
	}
	k = n * m - k + 1;
	ans1 = (k + n - 1) / n;
	if (ans1 % 2 == 0) {
		if (k % n == 0) {
			ans2 = 1;
		} else {
			ans2 = n - k % n + 1;
		}
	} else {
		if (k % n == 0) {
			ans2 = n;
		} else {
			ans2 = k % n;
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}
