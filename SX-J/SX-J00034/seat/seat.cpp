#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[110];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, res = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> h[i];
		if (h[i] > h[1])
			res++;
	}
	int x = ceil(res * 1.0 / n);
	int y = res % n;
	if (y == 0)
		y = n;
	if (x % 2 == 0)
		y = n + 1 - y;
	cout << x << " " << y;
	return 0;
}