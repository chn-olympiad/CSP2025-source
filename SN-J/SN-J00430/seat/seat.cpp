#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x = n * m;
	int a[105],b[105];
	int y;
	for (int i = 1;i <= x;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	y = a[1];
	sort(a+1,a+x+1);
	sort(b+1,b+x+1);
	for (int i = 1;i <= x;i++)
	{
		a[i] = b[x-i+1];
	}
	if (n == 1)
	{
		if (m == 1)
		{
			cout << 1 << " " << 1;
			return 0;
		}
		else
		{
			for (int i = 1;i <= m;i++)
			{
				if (y == a[i])
				{
					cout << i << " " << 1;
					return 0;
				}
			}
		}
	}
	if (m == 1)
	{
		for (int i = 1;i <= n;i++)
			{
				if (y == a[i])
				{
					cout << 1 << " " << i;
					return 0;
				}
			}
	}
	if (n == 2)
	{
		if (m == 2)
		{
			for (int i = 1;i <= x;i++)
			{
				if (y == a[i])
				{
					if (i <= 2)
					{
						cout << 1 << " " << i;
						return 0;
					}
					else
					{
						if (i == 3)
						{
							cout << 2 << " " << 2;
							return 0;
						}
						else
						{
							cout << 2 << " " << 1;
							return 0;
						}
					}
				}
			}
		}
		else
		{
			for (int i = 1;i <= x;i++)
			{
				if (y == a[i])
				{
					if (i % 4 == 0)
					{
						cout << i / 2 << " " << 1;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
