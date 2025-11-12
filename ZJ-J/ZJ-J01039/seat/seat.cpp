#include<bits/stdc++.h>
using namespace std;
int n, m, a[1006], r1, r = 0, c = 0, cnt = 0;
bool tmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
		if (i == 1)
		{
			r1 = a[i];
		}
	}
	sort(a + 1, a + 1 + n * m, tmp);
	for (int i = 1;i <= m;i++)
	{
		c++;
		for (int j = 1;j <= n;j++)
		{
			if (c % 2)
			{
				if (i == 1 || j != 1)
				{
					r++;
				}
			}
			else
			{
				if (j != 1)
				{
					r--;
				}
			}
			cnt++;
			//cout << c << ' ' << r << ' ' << a[cnt] << "\n";
			if (a[cnt] == r1)
			{
				cout << c << ' ' << r;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
