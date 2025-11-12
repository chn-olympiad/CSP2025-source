#include<cstdio>
#include<algorithm>
const int MAXN = 510;
const int MOD = 998244353;
int n, a[MAXN];
int mem[2][2010][110][5];
int dfs(int now, int suma, int maxa, int m)
{
	if(now > n) return suma > 2 * maxa && m >= 3;
	return mem[now & 1][suma][maxa][m];
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	int sum = 0, mmax = 0;
	for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]), sum += a[i], mmax = std::max(mmax, a[i]);
	for(int now = n; now >= 1; -- now)
	{
		for(int suma = 0; suma <= sum; ++ suma)
		{
			for(int maxa = 0; maxa <= mmax; ++ maxa)
			{
				for(int m = 0; m <= 3; ++ m)
				{
					int ans = 0;
					ans = (ans + dfs(now + 1, suma, maxa, m)) % MOD;
					ans = (ans + dfs(now + 1, suma + a[now], std::max(maxa, a[now]), (m == 3 ? 3 : m + 1))) % MOD;
					mem[now & 1][suma][maxa][m] = ans;
				}
			}
		}
	}
	printf("%d\n", dfs(1, 0, 0, 0));
	return 0;
}
