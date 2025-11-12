#include<bits/stdc++.h>
using namespace std;

int n, a[5005], c[5005], Max, ans;
bool b[5005];

void dfs(int k, int p, int l)
{
	if (k > p)
	{
		int sum = 0;
		int maxx = -1;
		for (int i = 1; i < k; i++)
		{
			sum += c[i];
			maxx = max(maxx, c[i]);
		}
		if (sum > maxx * 2)
		{
			ans = (ans + 1) % 998244353;
		}
		return ;
	}
	for (int i = l + 1; i <= n; i++)
	{
		if (!b[i])
		{
			b[i] = 1;
			c[k] = a[i];
			dfs(k + 1, p, i);
			b[i] = 0;
			c[k] = 0;
		}
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		Max = max(Max, a[i]);
	}
	if (Max == 1) cout << 0 << '\n';
	else
	{
		for (int i = 3; i <= n; i++)
		{
			memset(b, 0, sizeof(b));
			dfs(1, i, 0);
		}
	}
	cout << ans << '\n';
	return 0;
}
