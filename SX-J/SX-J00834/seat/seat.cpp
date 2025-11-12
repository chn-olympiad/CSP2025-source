#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int s, p;
int l, h;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (s == a[i]) {
			p = n * m - i + 1;
			break;
		}
	}
	//只有一列
	if (n == 1) {
		l = 1;
		h = p;
		cout << l << ' ' << h << endl;
		return 0;
	}
	//只有一行
	if (m == 1) {
		l = p;
		h = 1;
		cout << l << ' ' << h << endl;
		return 0;
	}
	//确定列
	if (p % n == 0) {
		l = p / n;
	} else {
		l = p / n + 1;
	}
	//确定行

	//奇数列
	if (l % 2 == 1) {
		if (p % n == 0) {
			h = n;
		} else {
			h = p % n;
		}
		cout << l << ' ' << h << endl;
	}
	//偶数列
	else {
		if (p % n == 0) {
			h = 1;
		} else {
			h = n - (p % n) + 1;
		}
		cout << l << ' ' << h << endl;
	}
	return 0;
}
