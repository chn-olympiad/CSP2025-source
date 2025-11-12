#include <bits/stdc++.h>
using namespace std;
int a[201];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i < n * m; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n *m, cmp);
	int l = 1, r = n * m - 1, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] < x)
			r = mid - 1;
		else {
			ans = mid;
			l = mid + 1;
		}
	}
	ans++;
	l = ceil(ans * 1.0 / n);
	cout << l << " ";
	if (l % 2 == 1) {
		if (ans % n == 0)
			cout << n;
		else
			cout << ans % n;
	} else {
		if (ans % n == 0)
			cout << 1;
		else
			cout << n - ans % n + 1;
	}

	return 0;
}
