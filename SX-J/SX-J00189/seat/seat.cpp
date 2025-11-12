#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a[105], b[105];
	int n, m, num;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int R = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		b[i] = a[n * m + 1 - i];
	}
	for (int i = 1; i <= n * m; i++) {
		if (b[i] == R) {
			num = i;
		}
	}
	if (num <= n) {
		cout << "1" << " " << num;
	} else {
		int q;
		if (num % n == 0) {
			q = num / n;
		} else {
			q = num / n + 1;
		}
		cout << q << " ";
		int p = num % n;
		if (q % 2 == 1) {
			if (p == 0) {
				cout << n;
			} else {
				cout << p;
			}
		} else {
			if (p == 0) {
				cout << "1";
			} else {
				cout << n + 1 - p;
			}
		}
	}
	return 0;
}
