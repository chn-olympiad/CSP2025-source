#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], sum, cnt, h, l, nm;

bool abc(int x, int y) {
	return x > y;
}

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i <= n * m - 1; i++) {
		cin >> a[i];
	}
	sum = a[0];
	sort(a, a + n *m - 1, abc);
	for (int i = 0; i <= n * m; i++) {
		if (a[i] == sum) {
			cnt = i + 1;
			break;
		}
	}
	if (cnt / m == 0 && cnt % m == 0) {
		l = cnt / m;
	} else {
		l = cnt / m + 1;
	}
	nm == cnt % m;
	if (l % 2 == 0) {
		h = m - nm;
	} else {
		h = 1 + nm;
	}
	cout << l << " " << h;
	return 0;
}