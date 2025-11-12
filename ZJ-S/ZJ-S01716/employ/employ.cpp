#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int ans = 0, n, m, s[505], c[505];
int vis[505], res[505];
char c_tmp[505];
void dfs(int x)
{
	if (x == n + 1)
	{
		int peo = 0, fal = 0;
		for (int i = 1; i <= n; i++)
		{
			if (fal >= c[res[i]] || s[i] == 0)
				fal++;
			else 
				peo++;
		}
		if (peo >= m)
			ans++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 1)
			continue;
		vis[i] = 1;
		res[x] = i;
		dfs(x + 1);
		vis[i] = 0;
	} 
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c_tmp[i];
	for (int i = 1; i <= n; i++)
		s[i] = c_tmp[i] - '0';
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 18)
	{
		dfs(1);
		cout << ans;
		return 0;
	}
	if (m == n)
	{
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c[i] == 0)
			{
				flag++;
				break;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == 0)
			{
				flag++;
				break;
			}
		}
		if (flag != 0)
		{
			cout << "0";
			return 0;
		}
		ans = 1;
		for (int i = 1; i <= n; i++)
			ans = ans * i % mod;
		cout << ans;
		return 0;
	}
	return 0;
}