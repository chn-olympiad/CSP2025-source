#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
struct node
{
	int x, y, z;
} a[100001];
void dfs(int now, int ans1, int ans2, int ans3, int sum)
{
	if (now == n + 1)
	{
		ans = max(ans, sum);
		return;
	}
	if (ans1 < n / 2)
		dfs(now + 1, ans1 + 1, ans2, ans3, sum + a[now].x);
	if (ans2 < n / 2)
		dfs(now + 1, ans1, ans2 + 1, ans3, sum + a[now].y);
	if (ans3 < n / 2)
		dfs(now + 1, ans1, ans2, ans3 + 1, sum + a[now].z);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int T = 1; T <= t; ++T)
	{
		int ttt = 0;
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i].x >> a[i].y >> a[i].z, ttt += max(max(a[i].x, a[i].y), a[i].z);
		if (n <= 17)
			dfs(1, 0, 0, 0, 0);
		else
			ans = ttt;
		cout << ans << '\n';
	}
	return 0;
}
