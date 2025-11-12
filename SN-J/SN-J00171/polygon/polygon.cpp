#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;

int n, a[maxn], ans;
void dfs (int now, int sum, int maxx, int num, int same)
{
	if (sum > 2 * maxx && num >= 3 && same == 1)
	{
		ans++;
		ans %= 998244353;
	}
	cout << now << ' ' << sum << ' ' << maxx << ' ' << num << ' ' << same  << ' ' << ans << '\n';
	if (now == n)
	{
		return;
	}
	dfs(now + 1, sum, maxx, num, 0);
	dfs(now + 1, sum + a[now], max(maxx, a[now]), num + 1, 1);
}
int main ()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n == 3)
	{
		int d = a[1] + a[2] + a[3];
		int maxxx = max(a[1], max(a[2], a[3]));
		if (d > 2 * maxxx)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, a[i], a[i], 1, 1);
	}
	cout << ans;
	return 0;
}
