#include <bits/stdc++.h>
using namespace std;
int a[107];
int v;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int x = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == x) {
			v = n * m - i + 1;
			break;
		}
	}
	if (v % (n * 2) != 0) {
		int b = v / (n * 2) * 2 ;
		v = v % (n * 2);
		if (v <= n) {
			cout << b + 1 << " ";
			cout << v;
		} else if (v > n && v <= 2 * n) {
			cout << b + 2 << " ";
			cout << n - v + n + 1;
		}
	} else if (v % (n * 2 ) == 0) {
		if (v % n != 0 ) {
			cout << 2 << " ";
			v -= n;
			cout << n - v + 1;
		} else if (v % (n * 2 ) == 0 && v / n != 0) {
			cout << 2 << " " << 1;
		} else {
			cout << 1 << " ";
			cout << v;
		}
	}
}
