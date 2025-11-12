#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, a[110], g[20][20];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	cin >> n >> m >> sx;
	a[1] = sx;
	for(int i = 2; i <= n * m; i++) cin >> a[i];
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 1, y = 1, pos = 1, flag = 0;
	while (true)
	{
		if (pos > n * m) break;
		g[x][y] = a[pos];
		if (x == 1 && flag == 1) 
		{
			y++, pos++;
			g[x][y] = a[pos];
			flag = 0;
		}
		if (x == n && flag == 0)
		{
			y++, pos++;
			g[x][y] = a[pos];
			flag = 1;
		}
		if (flag == 0) x++;
		else x--;
		pos++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (g[i][j] == sx)
			{
				cout << j << " " << i;
				return 0;
			}
		}	
	}
	return 0;
}