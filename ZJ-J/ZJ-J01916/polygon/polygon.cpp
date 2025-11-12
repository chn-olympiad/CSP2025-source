#include<bits/stdc++.h>
using namespace std;

int n, ans, l[5005], used[5005];

bool check(int m)
{
	int mx = 0, cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		if(used[i] > mx)
		{
			mx = used[i];
		}
		cnt += used[i];
	}
	if(cnt > 2 * mx)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void dfs(int m, int now)
{
	used[m] = l[now];
	if(m >= 3)
	{
		if(check(m))
		{
			
			ans++;
		}
	}
	for(int i = now + 1; i <= n; i++)
	{
		dfs(m + 1, i);
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i];
	}
	dfs(0, 0);
	cout << ans % 998244353 << endl;
	return 0;
}