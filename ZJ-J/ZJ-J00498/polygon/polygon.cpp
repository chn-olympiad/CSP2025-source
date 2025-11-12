#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
long long ans = 0, he;
int n, a[N];
void dfs(int num, int st, int ed)
{
	if (num == 0)
	{
		if (he > a[ed])
		{
			ans++;
		}
		return;
	}
	if (st == ed - 1)
	{
		return;
	}
	for (int i = 1; i <= ed - st - 1; i++)
	{
		he += a[st + i];
		dfs(num - 1, st + i, ed);
		he -= a[st + i];
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
    	cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++)
	{
		for (int j = 3; j <= n; j++)
		{
			dfs(i - 1, 0, j);
		}
	}
	cout << ans;
	return 0;
}
