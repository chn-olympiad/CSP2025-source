#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[50001];
void dfs(int now, int lst, int s, int yx)
{
	if (now == n + 1)
	{
		if (yx >= 3)
			if (s > a[lst] * 2)
				++ans;
		return;
	}
	dfs(now + 1, now, s + a[now], yx + 1);
	dfs(now + 1, lst, s, yx);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	dfs(1, 0, 0, 0);
	cout << ans << '\n';
	return 0;
}
