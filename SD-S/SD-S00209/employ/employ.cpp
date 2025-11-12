#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n, m, c[505], vis[505], cmax;
long long ans;
bool d[505];
void dfs(int now, int sum, int opt)
{
	if(now > n || sum >= m || opt >= cmax || n-now+1+sum < m)
	{
		if(sum >= m) ans++;
		ans %= 998244353;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == 1) continue;
		vis[i] = 1;
		if(!d[now] || opt >= c[i])
		{
			dfs(now+1, sum, opt+1);
		}
		else
		{
			dfs(now+1, sum+1, opt);
		}
		vis[i] = 0;
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	bool tt = 1;
	for(int i = 1; i <= n; i++)
	{
		char x;
		cin >> x;
		if(x == '1') d[i] = 1;
		else d[i] = 0, tt = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		cmax = max(c[i], cmax);
	}
	if(tt)
	{
		ans = 1;
		for(int i = 2; i <= n; i++)
		{
			ans*= i;
			ans %= 998244353;
		}
		cout << ans << '\n';
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans << '\n';
	return 0;
}
