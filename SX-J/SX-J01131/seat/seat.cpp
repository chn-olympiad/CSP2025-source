#include <bits/stdc++.h>
using namespace std;
const int MAXNM = 10 * 10 + 5;
int a[MAXNM];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int t, n, m, xr, ansc, ansr;
	cin >> n >> m;
	cin >> a[1];
	xr = a[1];
	t = n * m;
	for (int i = 2; i <= t; i++)
		cin >> a[i];
	sort(a + 1, a + t + 1);
	int whe = lower_bound(a + 1, a + n + 1, xr) - a;
	whe = t - whe + 1;
	ansc = (whe + n - 1) / n;
	if (whe % n == 0) {
		if (ansc & 1)
			ansr = n;
		else
			ansr = 1;
	} else {
		if (ansc & 1)
			ansr = whe % n;
		else
			ansr = n - whe % n + 1;
	}
	cout << ansc << " " << ansr;
	return 0;
}
