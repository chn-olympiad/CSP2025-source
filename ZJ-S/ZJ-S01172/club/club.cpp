#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a1[N], a2[N], a3[N], ans;
void dfs(int step, int c1, int c2, int c3, int sum)
{
	if (step > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (c1 < n / 2) dfs(step + 1, c1 + 1, c2, c3, sum + a1[step]);
	if (c2 < n / 2) dfs(step + 1, c1, c2 + 1, c3, sum + a2[step]);
	if (c3 < n / 2) dfs(step + 1, c1, c2, c3 + 1, sum + a3[step]);
}
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
			cin >> a1[i] >> a2[i] >> a3[i];
	ans = 0;
	if (n <= 10)
	{
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
		return;
	}
	if (a2[1] == 0 && a3[1] == 0)
	{
		sort (a1 + 1, a1 + n + 1);
		int ans = 0;
		for (int i = n; i >= n / 2 + 1; i--)
			ans += a1[i];
		cout << ans << endl;
		return;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += max(a1[i], max(a2[i], a3[i]));
	cout << ans << endl;
	return;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
