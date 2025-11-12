#include <bits/stdc++.h>
using namespace std;
int a[105], n, m, r, sum = 1, l, h;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n * m; i++)
		scanf("%d", &a[i]);
	r = a[0];
	for (int i = 1; i < n * m; i++) {
		if (a[i] > r)
			sum++;
	}
	if ((sum % n) == 0)
		l = sum / n;
	else
		l = sum / n + 1;
	if ((l % 2) == 1)
		h = sum - (l - 1) * n;
	else
		h = n - (sum - (l - 1) * n) + 1;
	cout << l << ' ' << h;
	return 0;
}