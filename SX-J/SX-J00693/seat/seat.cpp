#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005], p;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int o = a[1];
	sort(a + 1, a + 1 + (n *m));
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == o)
			p = n * m - i + 1;
	}
	if (p % n == 0) {
		cout << p / n << " " << n;
		return 0;
	} else {
		cout << p / n + 1 << " ";
		if ((p / n) % 2 == 1)
			cout << n - (p % n) + 1;
		else
			cout << p % n;
	}
	return 0;
}
