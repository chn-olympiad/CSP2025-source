#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5005, mod = 998244353;
int n, a[N], f[N][N];

int main()
{
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; ++ i)
	{
		f[i][a[i]] = 1;
		for (int j = 0; j <= 5000; ++ j)
		{
			f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
			if (a[i] <= j)
			{
				f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
			}
		}
		
		f[i][5001] = (f[i][5001] + f[i - 1][5001]) % mod;
		for (int j = 5000 - a[i] + 1; j <= 5001; ++ j)
		{
			f[i][5001] = (f[i][5001] + f[i - 1][j]) % mod;
		}
	}
	
	for (int i = 1; i <= n; ++ i)
	{
		for (int j = 5000; 1 <= j; -- j)
		{
			f[i][j] = (f[i][j] + f[i][j + 1]) % mod;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
	{
		ans = (ans + f[i - 1][a[i] + 1]) % mod;
	}
	
	cout << ans << endl;
	return 0;
}
