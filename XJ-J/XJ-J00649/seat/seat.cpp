#include <bits/stdc++.h>
using namespace std;
int n, m, a[101];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int z = a[1];
	bool flag = true;
	for (int i = 1; i <= n * m; i++)
	{
		for (int j = 2; j <= n * m; j++)
		{
			if (a[j - 1] < a[j])
			{
				flag = false;
			}
		}
		if (!flag)
		{
			for (int j = 2; j <= n * m; j++)
			{
				if (a[j - 1] < a[j])
				{
					int x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}
			}
		}
		else
		{
			break;
		}
		bool falg = true;
		for (int j = 2; j <= n * m; j++)
		{
			if (a[j - 1] < a[j])
			{
				falg = false;
			}
		}
		if (falg)
		{
			flag = true;
			break;
		}
	}
	int b;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] = z)
		{
			b = i;
		}
	}
	if (b <= n)
	{
		cout << "1" << " " << b;
	}
	else
	{
		int c = b / m;
		int d = (b - c) % n;
		if (c % 2 == 0)
		{
			cout << c << " " << d;
		}
		else
		{
			cout << c << " " << (n - (d - 1));
		}
	}
	return 0;
}
