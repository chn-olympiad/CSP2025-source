#include <bits/stdc++.h>
using namespace std;
int n, k, a[1010], ans = 0, f[1010][1010];

bool check(int s, int t)
{
	if (s == t)
	{
		if (a[s] == k) return true;
		return false;
	}
	if (t - s == 1)
	{
		if (a[t] ^ a[s] == k) return true;
		return false;
	}
	int pos = a[s] ^ a[s + 1];
	for (int i = s + 2; i <= t; i++)
	{
		pos = pos ^ a[i];
	}
	if (pos == k) return true;
	return false;
}

int main()
{
	cin >> n >> k;
	if (n > 1000)
	{
		cout << "0";
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int len = 0; len <= n - 1; len++)
	{
		for (int i = 1; i <= n; i++)
		{
			int j = i + len;
			if (j > n) continue;
			if (check(i, j)) f[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (f[i][j] == 1)
			{
				ans++;
				i = j;
			}	
		}
	}
	cout << ans;
	return 0;
}