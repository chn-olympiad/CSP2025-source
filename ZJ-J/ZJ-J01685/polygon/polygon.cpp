#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, a[5005], ans, tmp[5005];
void dfs(int x)
{
	if (x == n + 1)
	{
		long long sum = 0;
		long long maxn = 0;
		long long cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (tmp[i] == 1)
			{
				sum += a[i];
				maxn = max(maxn, a[i]);
				cnt++;
			}
		}
		if (cnt >= 3 && sum > 2 * maxn)
			ans++;
		return;
	}
	tmp[x] = 0;
	dfs(x + 1);
	tmp[x] = 1;
	dfs(x + 1);
	return;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n <= 20)
	{
		dfs(1);
		cout << ans;
		return 0;
	}
	ans = 1;
	for (int i = 1; i <= n; i++)
		ans = ans * 2 % mod;
	long long tem = 0;
	if (n % 2 == 0)
	{ 
		tem = n / 2;
		tem = tem * (n - 1) % mod;
	}
	else
	{
		tem = (n - 1) / 2;
		tem = tem * n % mod;
	}
	tem = (tem + n) % mod;
	ans += mod;
	ans -= tem;
	ans--;
	ans %= mod;
	cout << ans;
	return 0;
}