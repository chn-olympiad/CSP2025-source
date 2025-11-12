#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int a[105] = {};

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int r = a[1], rb;
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r)
			rb = i;
	}
	int l, h;
	if (rb % n == 0)
		l = rb / n;
	else
		l = rb / n + 1;
	if (l % 2 == 0)
		h = n + 1 - rb % n;
	else
		h = rb % n;
	if (h == 0)
		h = n;
	cout << l << " " << h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
