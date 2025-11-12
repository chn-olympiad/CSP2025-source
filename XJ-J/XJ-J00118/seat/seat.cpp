#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105];
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int t = a[1], c = 1;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[c] == t)
				{
					cout << i << " " << j;
					return 0;
				}
				c++;
			}
	    }
	    if (i % 2 == 0)
	    {
			for (int j = n; j >= 1; j--)
			{
				if (a[c] == t)
				{
					cout << i << " " << j;
					return 0;
				}
				c++;
			}
	    }
	}
	return 0;
}
