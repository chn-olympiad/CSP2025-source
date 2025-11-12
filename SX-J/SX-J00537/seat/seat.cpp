#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	int p = a[1];
	int c = 1;
	for (int i = 1; i <= m * n; i++) {
		if (a[i] > p)
			c++;
	}
	int q = ceil(c * 1.0 / (m * 2)) * 2 - 1 + (c - 1)  % (m * 2) / m;
	int r = q % 2 * (c % m + (c % m*(-m)) + m) + (q + 1) % 2 * (m - c % m + 1) ;
	cout << q << " " << r;
	return 0;
}
