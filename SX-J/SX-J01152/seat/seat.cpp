#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];

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
	int r = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	int b;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			b = i;
			break;
		}
	}
	if (b % n == 0) {
		if ((b / n) % 2 == 0) {
			cout << b / n << " " << 1;
		} else {
			cout << b / n << " " << n;
		}
	} else {
		int num = b % n ;
		if ((b / n + 1) % 2 == 0) {
			cout << b / n + 1 << " " << n + 1 - num;
		} else {
			cout << b / n + 1 << " " << num;
		}
	}
	return 0;
}