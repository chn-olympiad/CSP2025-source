#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen(seat.in, "r", stdin);
	freopen(seat.out, "w", stdout);
	int n, m, t, c;
	cin >> n >> m;
	t = n * m;
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
		c = a[1];
		if (a[i] > c) {
			swap(a[i], a[i - 1]);
		}
	}
	cout << c;
	return 0;
}
