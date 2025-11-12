#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], a1, xb = 1, xx, yy;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	a1 = a[1];
	for (int i = 2; i <= n * m; i++)
		if (a[i] > a1)
			xb++;
	if (xb % n == 0)
		xx = xb / n;
	else
		xx = xb / n + 1;
	if (xx % 2 == 0)
		if (xb % n == 0)
			yy = 1;
		else
			yy = (n + 1) - xb % n;
	if (xx % 2 == 1) {
		if (xb % n == 0)
			yy = n;
		else
			yy = xb % n;
	}
	cout << xx << ' ' << yy;
	return 0;

}