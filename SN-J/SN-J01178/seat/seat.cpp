#include <bits/stdc++.h>
using namespace std;
int a[105], n, m, c, r, xr, num;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	xr = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == xr)
		{
			num = i;
			break;
		}
	}
	if (num % n > 0) c = num / n + 1;
	else c = num / n;
	if (c % 2 == 0) r = c * n - num + 1;
	else r = n - c * n + num;
	cout << c << " " << r;
	return 0;
}
