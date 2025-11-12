#include <bits/stdc++.h>
using namespace std;
int a[105];
int cnt = 0;

bool cmp(int x, int y) {
	if (x != y) {
		return x > y;
	} else {
		return x >= y;
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int c, r;
	int n, m;
	cin >> n >> m;
	int j = n * m;
	for (int i = 1; i <= j; i++) {
		cin >> a[i];
	}
	int b = a[1];
	sort(a + 1, a + 1 + j, cmp);
	for (int i = 1; i <= j; i++) {
		if (a[i] == b) {
			cnt = i;
			break;
		}
	}
//	cout << cnt << endl;

	if (cnt % m == 0) {
		c = cnt / m  ;
	} else {
		c = cnt / m + 1;
	}
	if (cnt % n == 0) {
		if (c % 2 == 0)
			r = cnt % n + 1 ;
		else
			r = n;
	} else {
		r = cnt % n  ;
	}
//	cout << c << r << "----" << endl;
	if (c % 2 == 0) {
		cout << c << ' ' << n + 1 - r ;
	} else {
		cout << c << ' ' <<  r ;
	}
	return 0;
}
