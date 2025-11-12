#include <bits/stdc++.h>
using namespace std;
int s[101], n, i, m, xr, i1, wz, ls;
double hs1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> xr;
	for (i = 1; i < n * m; i++)
		cin >> s[i];
	sort(s, s + i);
	for (i1 = 1; i1 <=  n * m - 1; i1++) {
		if (s[i1] < xr) {
			wz++;
		} else
			break;
	}
	wz = n * m - wz;
	ls = wz / n;
	if (wz % n != 0)
		ls++;
	if (wz % n == 0) {
		cout << ls << " " << n;
		return 0;
	}
	if (ls % 2 == 1)
		cout << ls << " " << wz % n;
	else
		cout << ls << " " << n - (wz % n) + 1;
	return 0;
}
