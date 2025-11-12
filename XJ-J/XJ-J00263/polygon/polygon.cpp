#include <bits/stdc++.h>
using namespace std;
const int A = 998;
const int B = 244;
const int C = 353;
int n;
int a[5005];
long long ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	 
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int x = j + 1; x <= n; x++)
			{
				if ((a[i] + a[j] + a[x]) > (2 * a[x]))
					ans++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int x = j + 1; x <= n; x++)
			{
				for (int y = x + 1; y <= n; y++)
				{
					if ((a[i] + a[j] + a[x] + a[y]) > (2 * a[y]))
						ans++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int x = j + 1; x <= n; x++)
			{
				for (int y = x + 1; y <= n; y++)
				{
					for (int z = y + 1; z <= n; z++)
					{
						if ((a[i] + a[j] + a[x] + a[y]) > (2 * a[y]))
							ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
