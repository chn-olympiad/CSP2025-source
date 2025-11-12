#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n, m;
int x, y;
int me;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	me = a[1];
	sort(a + 1, a + n * m + 1);
	
	for (int i = n * m; i >= 1; i--)
	{
		if (a[i] == me)
		{
			me = n * m - (i - 1);
		}
	}
	if (me % n == 0)
		y = me / n;
	else
		y = me / n + 1;
	if (y % 2 == 0)
	{
		if (me % 2 != 0)
			x = n - (me % n - 1);
		else
			x = 1;
	}
	else
	{
		if (me % 2 != 0)
			x = me % n;
		else
			x = n;
	}
	cout << y << " " << x;
    return 0;
}
