#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n, m;
string s;
int c[505];
signed main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0); 
	//freopen("employ.in", "r", stdin);
	//freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	bool u = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (c[i] != '1')
			u = 0;
	}
	if (u)
	{
		int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			ans *= i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	else
	if (m == 1)
	{
		int ans = 1;
		
		return 0;
	}
	if (m == n)
	{
		bool g = 1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '0' || c[i + 1] == 0)
			{
				g = false;
				break;
			} 
		}
		if (g)
		{
			int ans = 1;
			for (int i = 1; i <= n; i++)
			{
				ans *= i;
				ans %= mod;
			}
			cout << ans;
		}
		else
			cout << 0;
		return 0;
	}
	return 0;
} 

