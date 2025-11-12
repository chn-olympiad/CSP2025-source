#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, k;
int a[N];
int ans;
int sum0, sum1;

int dfs (int i, int sum)
{
	ans = max (sum, ans);
	int u = 0;
	for (; i <= n; i ++)
	{
		u = u ^ a[i];
		if(u == k)
		{
			dfs(i + 1, sum + 1);
		}
		else dfs(i + 1, sum);
	}
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1;i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] == 1) sum1 ++;
		if (a[i] == 0) sum0 ++;
		
	}
	if (k == 0)
	{
		cout << sum0;
		return 0;
	}
	if (k == 1)
	{
		cout << sum1;
		return 0;
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
