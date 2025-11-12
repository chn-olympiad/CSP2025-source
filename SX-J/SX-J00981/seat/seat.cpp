#include <bits/stdc++.h>
using namespace std;

long long a[1000] = {0}, x, y, n, m;
bool cmp(long long c, long long b) {
	return c > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	long long t = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			t = i;
			break;
		}
	}
	if (t % n == 0) {
		x = t / n;
	} else {
		x = t / n + 1;
	}
	if (x % 2 == 0) {
		y = n - t + (x - 1) * n + 1;
	} else {
		y = t -  (x - 1) * n;
	}
	cout << x << "¡¡" << y;
	return  0;
}