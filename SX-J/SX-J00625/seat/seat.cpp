#include <bits/stdc++.h>
using namespace std;
int n, m, a[1015], b, c[1010][1010];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	b = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == b) {
			b = i;
		}
	}
	if (b % n != 0)
		cout << b / n + 1 << " ";
	else
		cout << b / n << " ";
	if ((b / n + 1) % 2 != 0) {
		cout << b + b % n;
	} else if ((b / n) % 2 != 0) {
		cout << b + b / n;
	}
	return 0;
}
