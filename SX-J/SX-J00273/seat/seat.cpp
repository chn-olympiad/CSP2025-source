#include <bits/stdc++.h>
using namespace std;
int n, m, y, c = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> y;
	for (int i = 1; i < n * m; i++) {
		int x;
		cin >> x;
		if (x > y) {
			c++;
		}
	}
	cout << ceil(c * 1.0 / n ) << ' ' << (c - 1) % n + 1;
	return 0;
}