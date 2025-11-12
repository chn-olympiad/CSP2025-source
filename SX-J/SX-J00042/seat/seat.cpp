#include <bits/stdc++.h>
using namespace std;
int n, m, a[100], r, rh, l, h;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> r;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	a[1] = r;
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = n * m; i >= 0; i--) {
		if (a[i] == r)
			rh = i;
	}
	//lльеп
	if (rh % n != 0)
		l = rh / n + 1;
	if (rh % n == 0)
		l = rh / n;
	//hльеп
	if (l % 2 == 0)
		h = n - rh % n + 1;
	if (l % 2 == 1)
		h = rh % n;
	if (h == 0)
		h = n;
	cout << l << " " << h;
	return 0;
}