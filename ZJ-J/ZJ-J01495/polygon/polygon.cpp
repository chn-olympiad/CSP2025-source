#include<bits/stdc++.h>
using namespace std;

int n, a[5010];
long long ans;

void dfs(int x, int last, int sum)
{
	if(x == 1)
	{
		for(int i = last + 1; i <= n; i++)
		{
			if(a[i] < sum)
			{
				ans = (ans + 1) % 998244353;
			}
		}
		return ;
	}
	for(int i = last + 1; i <= n - x + 1; i++)
	{
		dfs(x - 1, i, sum + a[i]);
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 3; i <= n; i++) dfs(i, 0, 0);
	cout << ans;
	return 0;
}
