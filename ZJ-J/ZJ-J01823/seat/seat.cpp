#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y;
int cnt = 1;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++)
	{
		cin >> y;
		if (i == 1)
			x = y;
		else if (y > x)
			cnt++;
	}
	
	x = 1, y = 1;
	for (int i = 2; i <= cnt; i++)
	{
		if (x % 2 == 1)
		{
			if (y != n)
				y++;
			else
				x++;
		}
		
		else
		{
			if (y != 1)
				y--;
			else
				x++;
		}
	}
	
	cout << x << " " << y;
	
	return 0;
}