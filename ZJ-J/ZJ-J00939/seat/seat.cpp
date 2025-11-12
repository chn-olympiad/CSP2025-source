/*luoguUID: 995899*/
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int l, h, a[N], r, tot, n, m, dir;
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1];
	stable_sort (a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++)
		if (r == a[i])
			tot = n * m - i + 1;
	dir = 1, h = 1;
	for (l = 1; l <= m; l++) {
		int lim;
		if (dir > 0) lim = n;
		else lim = 1;
		while (tot) {
			tot--;
			if (h == lim || (!tot)) break;
			h += dir;
		}
		if (!tot) break;
		dir = -dir;
	}
	cout << l << " " << h;
	return 0;
}