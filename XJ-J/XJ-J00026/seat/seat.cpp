#include <bits/stdc++.h>
using namespace std;
int n, m, cl, rh, a[105], xr, st;
int main()
{
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	xr = a[1];
	sort(a + 1, a + n * m + 1);
	for(int i = 1; i <= n * m; i++) if(a[i] == xr) st = n * m - i + 1;
	cl = st / n;
	if(st % n == 0)
	{
		if(cl % 2 != 0) rh = n;
		else rh = 1;
		cout << cl << " " << rh;
		return 0;
	}
	cl++;
	rh = st % n;
	if(cl % 2 == 0) rh = n + 1 - rh;
	cout << cl << " " << rh;
	return 0;
}
