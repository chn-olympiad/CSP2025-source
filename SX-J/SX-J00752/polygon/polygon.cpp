#include <bits/stdc++.h>
using namespace std;
int a[5005];

int max(int a, int b, int c, int d, int e) {
	if (a >= b && a >= c && a >= e && a >= d)
		return a;
	else if (b >= a && b >= c && b >= e && b >= d)
		return b;
	else if (c >= a && c >= b && c >= d && c >= e)
		return c;
	else if (d >= a && d >= b && d >= c && d >= e)
		return d;
	else if (e >= a && e >= b && e >= d && e >= c)
		return e;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[1] + a[2] + a[3] >= 2 * max(a[1], a[2], a[3], 0, 0))
		sum++;
	if (a[1] + a[2] + a[3] + a[4] >= 2 * max(a[1], a[2], a[3], a[4], 0))
		sum++;
	if (a[1] + a[2] + a[4] >= 2 * max(a[1], a[2], 0, a[4], 0))
		sum++;
	if (a[1] + a[3] + a[4] >= 2 * max(a[1], 0, a[3], a[4], 0))
		sum++;
	if (a[2] + a[3] + a[4] >= 2 * max(0, a[2], a[3], a[4], 0))
		sum++;
	if (a[1] + a[2] + a[3] + a[4] + a[5] >= 2 * max(a[1], a[2], a[3], a[4], a[5]))
		sum++;
	if (a[2] + a[3] + a[4] + a[5] >= 2 * max(0, a[2], a[3], a[4], a[5]))
		sum++;
	if (a[1] + a[3] + a[4] + a[5] >= 2 * max(a[1], 0, a[3], a[4], a[5]))
		sum++;
	if (a[1] + a[2] + a[4] + a[5] >= 2 * max(a[1], a[2], 0, a[4], a[5]))
		sum++;
	if (a[1] + a[2] + a[3] + a[5] >= 2 * max(a[1], a[2], a[3], a[5], 0))
		sum++;
	if (a[1] + a[2] + a[5] >= 2 * max(a[1], a[2], 0, a[5], 0))
		sum++;
	if (a[1] + a[3] + a[5] >= 2 * max(a[1], 0, a[3], a[5], 0))
		sum++;
	if (a[2] + a[3] + a[5] >= 2 * max(0, a[2], a[3], a[5], 0))
		sum++;
	if (a[1] + a[5] + a[4] >= 2 * max(a[1], a[2], 0, a[4], 0))
		sum++;
	if (a[5] + a[3] + a[4] >= 2 * max(a[1], 0, a[3], a[4], 0))
		sum++;
	if (a[2] + a[5] + a[4] >= 2 * max(0, a[2], a[3], a[4], 0))
		sum++;
	if (n = 3) {
		if (a[1] + a[2] + a[3] >= 2 * max(a[1], a[2], a[3], 0, 0))
			cout << 1;
		else
			cout << 0;
	} else
		cout << sum;
	return 0;
}
