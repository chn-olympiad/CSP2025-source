#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], ans, cnt;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	ans = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == ans) {
			cnt = i;
		}
		continue;
	}
	if (cnt / n % 2 == 1) {
		if (cnt % n != 0) {
			cout << cnt / n + 1 << " " << cnt % n + 1;
		} else {
			cout << m << " " << n;
		}
	} else {
		if (cnt % n != 0) {
			cout << cnt / n + 1 << " " << cnt % n;
		} else {
			cout << m << " " << 1;
		}
	}
	return 0;
}
