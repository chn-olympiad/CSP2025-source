#include <bits/stdc++.h>
using namespace std;
int f[10000][10000], t, n;
int a[10000][4];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	cin >> t;
	for (int u = 1; u <= t; u++)
	{
		memset(a, 0, sizeof(0));
		memset(f, -1e9, sizeof(f));
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			sum = sum + a[i][3];
		}
		f[0][0] = sum;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				for (int k = i-j; k >= 0; k--)
				{
					if (j > 0)
					{
						f[j][k] = max(f[j][k], f[j-1][k]-a[i][3] + a[i][1]);
					}
					if (k > 0)
					{
						f[j][k] = max(f[j][k], f[j][k-1]-a[i][3] + a[i][2]);
					}
				}
			}
		}
		int ans = -1;
		for (int j = 0; j <= n/2; j++)
		{
			for (int k = 0; k <= n/2; k++)
			{
				if (j + k >= n/2)
				{
					ans = max(ans, f[j][k]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
 }
