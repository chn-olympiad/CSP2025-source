#include <bits/stdc++.h>
using namespace std;

int mod =  998244353;
long long cnt = 0;
int n, m, a[505];
bool vis[505];
string p;

void f(int x, int y, int z)
{
	if (x > n)
	{
		if (z >= m)
		{
			cnt++;
			cnt %= mod;
		}
	}
	int lp = 0;
	for(int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (p[x - 1] == '0' || y >= a[i])
			{
				lp = 1;
			}
			vis[i] = 1;
			f(x + 1, y + lp, z + 1 - lp);
			vis[i] = 0;
			lp = 0;
		}
	}
	return;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	bool is0 = false;
	int cnt0 = 0;
	for(int i = 0; i < n; i++)
	{
		if (p[i] == '0')
		{
			is0 = true;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		cnt0++;
	}
	if (n <= 18)
	{
		f(1, 0, 0);
		cout << (cnt % mod);
		return 0;
	}
	if (is0)
	{
		cout << 0;
	}
	else
	{
		if (n - cnt0 < m)
		{
			cout << 0;
			return 0;
		}
		long long ans = 1, ans2 = 1;
		for(int i = 2; i <= n - cnt0; i++)
		{
			ans *= i;
			ans %= mod;
		}
		for(int i = 2; i <= cnt0; i++)
		{
			ans2 *= i;
			ans2 %= mod;
		}
		ans += ans2;
		ans %= mod;
		cout << ans;
	}
	return 0;
}
