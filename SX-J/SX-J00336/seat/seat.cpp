#include <bits/stdc++.h>
using namespace std;
int n, m, bh;
int a[1000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	bh = a[1];
	sort(a + 1, a + n *m + 1);
	int x = 0, y = 0, cnt, num = 0;
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == bh) {
			cnt = n * m - i + 1;
			break;
		}
		num++;
	}
	num /= n;
	if (num % 2 == 0) {
		x = num + 1;
		y = cnt - num * n;
	} else {
		x = num + 1;
		y = n + 1 - (cnt - num *n) ;
	}
	cout << x << " " << y;
	return 0;
}
