#include <bits/stdc++.h>
using namespace std;
int a[15][15], r[105], a1, cnt;
int n, m;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> r[i];
	}
	a1 = r[1];
	sort(r + 1, r + (n * m) + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 1; j <= m; j++)
			{
				cnt++;
				a[i][j] = r[cnt];
				if (r[cnt] == a1)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for (int j = m; j >= 1; j--)
			{
				cnt++;
				a[i][j] = r[cnt];
				if (a1 == r[cnt])
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
 } 
