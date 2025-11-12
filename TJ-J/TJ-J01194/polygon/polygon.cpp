#include <bits/stdc++.h>

using namespace std;

int n, a[5005], ans;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	///
	if (n <= 3) if (a[1] + a[2] > a[3] and a[2] + a[3] > a[1] and a[1] + a[3] > a[2]) ans++;
	else
	{
		for (int i = 1;i <= n - 3;i++) 
		{
			for (int j = i + 1;j <= n-2;j++)
			{
				for (int k = j + 1; k <= n-1;k++)
				{
					for (int l = k + 1;l <= n ;l++)
					{
						if (a[i] + a[j] + a[k] > a[l] and a[i] + a[j] + a[l] > a[k] and a[j] + a[k] + a[l] > a[i] and a[i] + a[k] + a[l] > a[j]) ans++;
					}
				}
			}
		}
		for (int j = 1;j <= n-2;j++)
		{
			for (int k = j + 1; k <= n-1;k++)
			{
				for (int l = k + 1;l <= n ;l++)
				{
					if (a[j] + a[k] > a[l] and a[j] + a[l] > a[k] and a[k] + a[l] > a[j]) ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
