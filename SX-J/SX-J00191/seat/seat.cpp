#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = n * m;
	for (int i = 1; i <= sum; i++) {
		cin >> a[i];
	}
	int x, cnt = 0;
	x = a[1];
	sort(a + 1, a + 1 + sum, greater<int>());
	for (int i = 1; i <= sum; i++) {
		if (a[i] == x) {
			cnt = i;
			break;
		}
	}
//	cnt = sum - cnt;
//	cout << cnt << endl;
	int r, c;
	if (cnt % n == 0) {
		c = cnt / n;
	} else
		c = cnt / n + 1;

	if (cnt % n == 0) {
		if (c % 2 == 1)
			r = n;
		else
			r = 1;
	} else
		r = cnt % n;
//	cout << cnt;
//	cout << endl;
	if (c % 2 == 1) {
		cout << c << " " << r;
	} else if (cnt % n == 0) {
		cout << c << " " << r;
	} else
		cout << c << " " << n - r + 1;
	return 0;
}