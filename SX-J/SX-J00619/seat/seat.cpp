#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005], xm, ans;

bool cmp(int x, int y) {
	return y < x;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	xm = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == xm)
			ans = i;
	}
	if ((ans + n - 1) / n % 2 == 1) {
		cout << (ans + n - 1) / n << ' ';
		ans % n == 0 ? cout << n : cout << ans % n;
	} else {
		cout << (ans + n - 1) / n << ' ' << n - ans % n + 1;
	}
	return 0;
}