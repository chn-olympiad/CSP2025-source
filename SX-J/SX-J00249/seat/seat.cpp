#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], t, ans;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	t = a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			ans = i;
			break;
		}
	}
	if (ans % n == 0) {
		cout << ans / n << ' ';
		if ((ans / n) % 2 == 0)
			cout   << 1;
		else
			cout << n;
	} else {
		cout << ans / n + 1 << ' ';
		if ((ans / n) % 2 == 0)
			cout << ans % n;
		else
			cout << n + 1 - ans % n;
	}
	return 0;
}
