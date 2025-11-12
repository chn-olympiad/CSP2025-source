#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (a[i] == r)
			cout << (i + n - 1) / n << ' ' << (((i + n - 1) / n % 2 == 1) * ((i - 1) % n + 1) + ((i + n - 1) / n % 2 == 0) * (n -
			                                   (i - 1) % n));
	return 0;
}