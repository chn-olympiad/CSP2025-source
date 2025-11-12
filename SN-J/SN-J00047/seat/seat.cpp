#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], pos;
bool cmp(int c, int d)
{
	return c > d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int t = n * m;
	for (int i = 1; i  <= t; i++) cin >> a[i];
	int k = a[1];
	sort(a + 1, a + t + 1, cmp);
	for (int i = 1; i <= t; i++)
	{
		if (a[i] == k)
		{
			pos = i;
			break;
		}
	}
	int z = 1, x = 1, y = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (i % 2 == 0) y--;
			else y++;
			z++;
			if (z == pos)
			{
				cout << x << " " << y;
				return 0;
			}
			
		}
		x++;
		z++;
		if (z == pos)
		{
			cout << x << " " << y;
			return 0;
		}
	}
	return 0;
 } 
