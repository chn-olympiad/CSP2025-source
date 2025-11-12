#include<iostream>
#include<cstdio>
using namespace std;
int n, m, test[505], people[505], ans;
bool vis[505];
void dfs(int id, int can)
{
	if (can < m)
	{
		return ;
	}
	else if (id == n+1)
	{
		ans = (ans+1)%998244353;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
		{
			continue;
		}
		int tmp = (n-can >= people[i] || test[id] == 0);
		vis[i] = 1;
		dfs(id+1, can-tmp);
		vis[i] = 0;
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		test[i] = c-'0';
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> people[i];
	}
	dfs(1, n);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
