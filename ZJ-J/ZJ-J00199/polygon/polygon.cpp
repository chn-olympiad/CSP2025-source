#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 505, mod = 998244353;

int n, maxn = 0, sum = 0, res = 0;
int a[N], f[2][N * 2][N], ff[25];

void check()
{
	int maxn = 0, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(ff[i])
		{
			maxn = max(maxn, a[i]);
			sum += a[i];
		}
	}
	if(sum <= maxn * 2) return;
	res++;
}

void dfs(int dep)
{
	if(dep > n)
	{
		check();
		return;
	}
	ff[dep] = 0;
	dfs(dep + 1);
	ff[dep] = 1;
	dfs(dep + 1);
}

int quickpow(int x, int p)
{
	int res = 1;
	for( ; p; p >>= 1)
	{
		if(p & 1) res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}

signed main()
{
	//cout << quickpow(2, 8) << "\n";
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	bool fff = 1;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
		sum += a[i];
		if(a[i] != 1) fff = 0;
	}
	if(n <= 20)
	{
		dfs(1);
		cout << res << "\n";
		return 0;
	}
	if(fff)
	{
		int res = quickpow(2, n);
		res--;
		res = res - n - n * (n - 1) / 2;
		cout << res << "\n";
		return 0;
	}
	f[0][0][0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= maxn * 2; j++)
			for(int k = 0; k <= maxn; k++)
				f[(i & 1) ^ 1][j][k] = f[i & 1][j][k];
		for(int j = 0; j <= maxn * 2; j++)
			for(int k = 0; k <= maxn; k++)
			{
				f[(i & 1) ^ 1][min(maxn * 2, j + a[i])][max(a[i], k)] += f[i & 1][j][k];
				f[(i & 1) ^ 1][min(maxn * 2, j + a[i])][max(a[i], k)] %= mod;
			}
	}
	int res = 0;
	for(int j = 1; j <= maxn * 2; j++)
		for(int k = 1; k * 2 < j; k++)
			res += f[n & 1][j][k];
	//cout << f[0][0][0] << "\n";
	cout << res % mod << "\n";
	return 0;
}
