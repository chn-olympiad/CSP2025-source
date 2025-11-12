#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, b;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
		cin >> a[i];
	b = a[0];
	sort(a, a + (n *m));
	int c = upper_bound(a, a + (n *m), b) - a + 1;
	int d = c / n, e = c % n;
	if (e == 0)
		e = n;
	if (d % 2 == 0)
		e = n - e + 1;
	cout << d << " " << e;
	return 0;
}
