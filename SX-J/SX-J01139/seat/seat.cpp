#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 1, a, b, l, p;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> b;
	for (int i = 2; i <= n * m; i++) {
		cin >> a;
		if (a > b)
			cnt++;
	}
	l = (cnt - 1) / n + 1;
	p = (cnt - 1) % n + 1;
	cout << l << " ";
	if (l % 2 == 0)
		cout << n - p + 1;
	else
		cout << p;
	return 0;
}
