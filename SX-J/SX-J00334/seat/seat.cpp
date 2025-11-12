#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], k, c;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	k = a[1];
	sort(a + 1, a + 1 + n *m);
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == k)
			c = n * m - i + 1;
	}
	if (c <= m)
		cout << 1 << " " << c;
	else if (m == 1)
		cout << c << " " << 1;
	else if (c >= m && n == 2 && m == 2)
		cout << 2 << " " << 4 - c + 1;
	else
		cout << c / n + 1 << " " << c % n;
	//cout << c;
	return 0;
}
