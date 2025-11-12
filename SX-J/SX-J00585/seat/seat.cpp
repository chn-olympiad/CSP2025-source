#include <bits/stdc++.h>
using namespace std;
int n, m;
int r, a;
int c = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> r;
	for (int i = 0; i <= n * m; i++) {
		cin >> a;
		if (a > r) {
			c++;
		}
		if (n / 2 == 0) {
			cout << c / m + 1 << " " << m - (c - 1) % m;
		} else {
			cout << c / m + 1 << " " << c % m;
		}
	}
	return -0
}