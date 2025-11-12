#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], r, x, y, d, ind;
int main()	{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)	cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= m; ++i)	{
		ind++;
		if (i & 1)	{
			x = 1;
			y = i;
			d = 1;
		}	else	{
			x = n;
			y = i;
			d = -1;
		}
		if (a[ind] == r)	{
			cout << y << ' ' << x << endl;
			return 0;
		}
		for (int j = 2; j <= n; ++j)	{
			x += d;
			if (a[++ind] == r)	{
				cout << y << ' ' << x << endl;
				return 0;
			}
		}
	}
	return 0;
}