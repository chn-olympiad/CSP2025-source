#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int mo = 998244353;
int a[5010];
bool f[5010];
int m;
int cnt = 0;
long long c[5010];

void dfs(int x, int n, int sum, int maxn, int j)
{
	
	if (x > n)
	{
		if (sum > 2 * maxn)
		{
			cnt++;
			cnt %= mo;
		}
		return ;
	}
	if (sum > 2 * maxn)
	{
		cnt++;
		cnt %= mo;
	}
	for (int i = j + 1; i <= m; i++)
	{
		if (!f[i])
		{
			f[i] = true;
			dfs(x + 1, n, sum + a[i], max(maxn, a[i]), i);
			f[i] = false;
		}
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m;
	bool fl = true;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			fl = false;
		}
	}
	if (m < 3)
	{
		cout << 0;
		return 0;
	}
	if (fl)
	{
		c[0] = 1;
		for (int i = 1; i <= m; i++)
		{
			c[i] = c[i - 1] * i % mo;
		}
		long long sum = 0;
		for (int i = 3; i <= m; i++)
		{
			sum += c[m] / c[i] / c[m - i];
			sum %= mo;
		}
		cout << sum;
		return 0;
	}
	sort(a + 1, a + m + 1);
	dfs(1, m, 0, 0, 0);
//	for (int i = 3; i <= m; i++)//sum > a[i](sum求和a1~ai任选)
//	{
//		dfs(1, i, 0, 0, 0);
//	}
	cout << cnt % mo;
	return 0;
}
