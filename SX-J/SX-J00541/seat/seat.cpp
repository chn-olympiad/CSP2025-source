#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[1005], num;

bool cmp(int x, int y) {
	return x > y;
}

int rx = 1, ry = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	num = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	int id = 1;
	while (1) {
		if (a[id] == num) {
			cout << ry << " " << rx;
			return 0;
		}
		for (int i = 1; i < n; i ++) {
			rx ++;
			id ++;
			if (a[id] == num) {
				cout << ry << " " << rx;
				return 0;
			}
		}
		ry ++;
		id ++;
		if (a[id] == num) {
			cout << ry << " " << rx;
			return 0;
		}
		for (int i = 1; i < n; i ++) {
			rx --;
			id ++;
			if (a[id] == num) {
				cout << ry << " " << rx;
				return 0;
			}
		}
		ry ++;
		id ++;
	}
	return 0;
}
