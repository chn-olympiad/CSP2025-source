#include <bits/stdc++.h>
using namespace std;
long long n, m, p, q, w;
long long a[105];

inline bool cmp(int x, int y) {
	return x > y;
}

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	w = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == w)
			w = i;
	}
	p = w / n;
	int s = w % n;
	if (s != 0)
		p += 1;
	else
		s = n;
	if (p % 2 != 0)
		q = s;
	else
		q = n - s + 1;
	cout << p << " " << q;

	return 0;
}
