#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
long long n, a[5001], ans;

void dfs(int p, int x, int q, int k)
{
	if (k == p)
	{
		if (x > 2 * a[q])
		{
			ans++;
			ans %= mod;
		}
		return;
	}
	for (int i = q + 1; i <= n; i++)
	{
		dfs(p, x + a[i], i, k + 1);
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++)
	{
		dfs(i, 0, 0, 0);
	}
	cout << ans;
	return 0;
}
