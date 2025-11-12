#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], p, l, h;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int x = n * m;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
	}
	int f = a[1];
	sort(a + 1, a + 1 + x, cmp);
	for (int i = 1; i <= x; i++) {
		if (f == a[i]) {
			p = i;
			break;
		}
	}
	if (p % n == 0)
		l = p / n;
	else
		l = p / n + 1;
	if (l % 2 == 1) {
		if (p % n == 0)
			h = n;
		else
			h = p % n;
	} else {
		if (p % n == 0)
			h = 1;
		else
			h = n - p % n + 1;
	}
	cout << l << ' ' << h;
	return 0;
}