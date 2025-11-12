#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int a[5005];
const ll MOD = 998244353;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	//n = 8
	if (n == 1 || n == 2)
	{
		cout << "0\n";
		return 0;
	}
	ll tot = 0;
	if (n >= 3)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					int cnt = a[i] + a[j] + a[k];
					int maxn = max(a[i], max(a[j], a[k]));
					if (cnt > maxn * 2) ans++;
				}
			}
		}
		tot += ans;
	}
	if (n >= 4)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					for (int l = k + 1; l <= n; l++)
					{
						int cnt = a[i] + a[j] + a[k] + a[l];
						int maxn = max(a[i], max(a[j], max(a[k], a[l])));
						if (cnt > maxn * 2) ans++;
					}
				}
			}
		}
		tot += ans;
	}
	if (n >= 5)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					for (int l = k + 1; l <= n; l++)
					{
						for (int b = l + 1; b <= n; b++)
						{
							int cnt = a[i] + a[j] + a[k] + a[l] + a[b];
							int maxn = max(a[i], max(a[j], max(a[k], max(a[l], a[b]))));
							if (cnt > maxn * 2) ans++;
						}
					}
				}
			}
		}
		tot += ans;
	}
	if (n >= 6)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					for (int l = k + 1; l <= n; l++)
					{
						for (int b = l + 1; b <= n; b++)
						{
							for (int c = b + 1; c <= n; c++)
							{
								int cnt = a[i] + a[j] + a[k] + a[l] + a[b] + a[c];
								int maxn = max(a[i], max(a[j], max(a[k], max(a[l], max(a[b], a[c])))));
								if (cnt > maxn * 2) ans++;
							}
						}
					}
				}
			}
		}
		tot += ans;
	}
	if (n >= 7)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					for (int l = k + 1; l <= n; l++)
					{
						for (int b = l + 1; b <= n; b++)
						{
							for (int c = b + 1; c <= n; c++)
							{
								for (int d = c + 1; d <= n; d++)
								{
									int cnt = a[i] + a[j] + a[k] + a[l] + a[b] + a[c] + a[d];
									int maxn = max(a[i], max(a[j], max(a[k], max(a[l], max(a[b], max(a[c], a[d]))))));
									if (cnt > maxn * 2) ans++;
								}
							}
						}
					}
				}
			}
		}
		tot += ans;
	}
	if (n >= 8)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					for (int l = k + 1; l <= n; l++)
					{
						for (int b = l + 1; b <= n; b++)
						{
							for (int c = b + 1; c <= n; c++)
							{
								for (int d = c + 1; d <= n; d++)
								{
									for (int e = d + 1; e <= n; e++)
									{
										int cnt = a[i] + a[j] + a[k] + a[l] + a[b] + a[c] + a[d] + a[e];
										int maxn = max(a[i], max(a[j], max(a[k], max(a[l], max(a[b], max(a[c], max(a[d], a[e])))))));
										if (cnt > maxn * 2) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		tot += ans;
	}
	tot %= MOD;
	cout << tot << "\n";
	return 0;
}

