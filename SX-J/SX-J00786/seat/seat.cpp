#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], c[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	if (a[1] == 100) {
		cout << '1' << " " << '1';
		return 0;
	}
	int s = 0;
	for (int i = 2; i <= n * m; i++) {
		if (a[i] > a[1]) {
			s++;
		}
	}
	s = s + 1;
	if (s % n == 0) {
		if ( s / n % 2 == 0) {
			cout << s / n << " " << '1';
		} else {
			cout << s / n << " " << n;
		}
	} else {
		if ((s / n + 1) % 2 == 0) {
			cout << s / n + 1 << " " << n + 1 - s % n;
		} else {
			cout << s / n + 1 << " " << s % n;
		}
	}






















	return 0;
}