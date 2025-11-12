#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool A = 1, B = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
			A = 0;
		if (a[i] > 1)
			B = 0;
	}
	if (A == 1 && k == 0)
	{
		cout << n / 2;
		return 0;
	}
	else
	{
		if (B == 1)
		{
			int now = a[1];
			for (int i = 2; i <= n; i++)
			{
				if (now == k)
				{
					now = a[i];
					ans++;
				}
				else
					now ^= a[i];
			}
			if (now == k)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
