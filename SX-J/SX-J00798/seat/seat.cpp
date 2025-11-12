#include <bits/stdc++.h>
using namespace std;

int n, m, a[101], c, r, s, u, d[2] = {-1, 1};

bool bj(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= (n * m); i++)
		cin >> a[i];
	s = a[1];
	sort(a + 1, a + n *m + 1, bj );
	for (int i = 1; i <= (n * m); i++)
		if (a[i] == s)
			u = i;
	if ((u % n) > 0) {
		c = u / n + 1;
	} else
		c = (u / n);

	r = n - ((d[c % 2] - 1) / 2) + d[c % 2] * (u % n);
	r = r % n;
	if (r == 0)
		r = n;
	cout << c << ' ' << r;
}
