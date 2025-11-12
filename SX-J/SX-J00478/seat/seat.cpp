#include <bits/stdc++.h>
using namespace std;
int a[1000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, l, k, c, f = 0;
	cin >> n >> m;
	c = n * m;
	for (int i = 1; i <= c; i++)
		cin >> a[i];
	l = a[1];
	sort(a + 1, a + c + 1);
	for (int i = c; i >= 1; i--) {
		f++;
		if (a[i] == l)
			k = f;
	}
	if (k % n == 0)
		cout << n << " " << k / n;
	if (k % n != 0) {
		if ((k / n + 1) % 2 == 0)
			cout << k / n + 1 << " " << n - (k % n) + 1;
		if ((k / n + 1) % 2 != 0)
			cout << k / n + 1 << " " << k % n;
	}
	return 0;
}
