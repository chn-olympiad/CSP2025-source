#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int sum = 0;
		int m, maxn = -1;
		cin >> m;
		int a[4][10005], b[10005], c[10005], d[10005];
		for (int j = 1;j <= m;j++)
		{
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			b[j] = a[j][1];
			c[j] = a[j][2];
			d[j] = a[j][3];
		}
		if (m == 2)
		{
			for (int j = 1;j <= 3;j++)
			{
				for (int u = 1;u <= 3;u++)
				{
					if (u == j)
					{
						continue;
					}
					maxn = max(maxn,a[1][j] + a[2][u]);
				}
			}
			sum += maxn;
			cout << sum << endl;
			
		}
		if (m == 3)
		{
			sort (b + 1, b + m + 1);
			sort (c + 1, c + m + 1);
			sort (d + 1, d + m + 1);
			sum += b[m] + c[m] + d[m];
			cout << sum << endl;
		}
		if (m == 4)
		{
			sort (b + 1, b + m + 1);
			sort (c + 1, c + m + 1);
			sort (d + 1, d + m + 1);
			sum += b[m] + c[m] + d[m];
			b[m] = 0;
			c[m] = 0;
			d[m] = 0;
			sort (b + 1, b + m + 1);
			sort (c + 1, c + m + 1);
			sort (d + 1, d + m + 1);
			sum += max(max(b[m],c[m]),d[m]);
			cout << sum << endl;
		}
	}
	return 0;
} 
