#include <bits/stdc++.h>
#define LL long long
#define DB double
#define ST string

#define fr(x, y, z) for(int x = (y); x <= (z); x ++ )
#define dfr(x, y, z) for(int x = (y); x >= (z); x -- )

using namespace std;

const int N = 5010, MOD = 998244353;
int n, a[N], f[502][102][202];

int res;
void dfs(int x, LL sum, int mx)
{
	if(x == n + 1)
	{
		if(sum > 2ll * mx) res = (res + 1) % MOD;
		return ; 
	}
	
	dfs(x + 1, sum, mx);
	dfs(x + 1, sum + 1ll * a[x], max(mx, a[x]));
}

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int MX = 0;
	fr(i, 1, n) cin >> a[i], MX = max(MX, a[i]);
	
	if(MX == 1)
	{
		res = 1;
		fr(i, 1, n) res = 2ll * res % MOD;
		res = (res + MOD - ((1ll * n * (n - 1) / 2) % MOD + n + 1) % MOD) % MOD;
	}
	else dfs(1, 0, 0);
//	else if(MX <= 200)
//	{
//		f[1][a[1]][a[1] - 1] = 1;
//		fr(i, 1, n) fr(j, 1, MX) dfr(k, MX * 2 + 1, 0)
//		{
//			f[i][j][k] = (1ll * f[i][j][k] + f[i - 1][j][k] + f[i][j][k + 1]) % MOD;
//			f[i + 1][max(j, a[i + 1])][min(MX * 2 + 1, k + a[i + 1])] = (1ll * f[i + 1][max(j, a[i + 1])][min(MX * 2 + 1, k + a[i + 1])] + f[i][j][k]) % MOD;
//			
//			cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << '\n';
//		}
//		
//		fr(i, 1, n) res = (1ll * res + f[n][a[i]][a[i] * 2]) % MOD;
//	}
	
	cout << res << '\n';
	
	return 0;
}

// Happy birthday, LXH!
