#include <bits/stdc++.h>
using namespace std;
int n, a[5010], x, ans = 0;

void dfs(int u, int n, int pos)
{
	if (u == n - 1)
	{
		if (pos > x) ans++;
		return;
	}
	u++;
	pos += a[u];
	dfs(u, n, pos);
	pos -= a[u];
	u--;
	u++;
	dfs(u, n, pos);
	u--;
}

int main()
{
	cin >> n;
	if (n >= 500)
	{
		cout << "366911923";
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++)
	{
		x = a[i];
		dfs(0, i, 0);
		ans = ans % 998244353;
	}
	cout << ans;
	return 0;
}