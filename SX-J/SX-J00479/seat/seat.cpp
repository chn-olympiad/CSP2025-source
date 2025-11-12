#include <bits/stdc++.h>
using namespace std;
int m, n, a[10000], x = 1, h, l;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= m * n; i++) {
		if (a[1] < a[i])
			x++;
	}
	l = (x + n - 1) / n;
	if (l % 2 == 1) {
		h = x % n;
		if (h == 0)
			h = n;
	}
	if (l % 2 == 0) {
		h = l * n + 1 - x;
	}
	cout << l << " " << h;
}
