#include <bits/stdc++.h>
using namespace std;

namespace p1
{
	const int MAXN = 5010;
	const int mod = 998244353;
	int n, a[MAXN], s[MAXN];
	int hasmem[MAXN][MAXN][2];
	long long dp1(int p, int sum, int mx)
	{
		if(p > n)
		{
			if(sum > 2 * mx) return 1;
			return 0;	
		}
		long long ans = 0;
		ans = ans + (dp1(p + 1, sum, mx) % mod) % mod;
		ans = (ans + dp1(p + 1, sum + a[p], max(mx, a[p])) % mod ) % mod;
		return ans;
	}
	
	long long dp2(int p, int sum, int mx)
	{
		if(p > n)
		{
			if(sum > 2 * mx) return 1;
			return 0;	
		}
		if(hasmem[p][sum][mx] != -1) return hasmem[p][sum][mx];
		long long ans = 0;
		ans = ans + (dp2(p + 1, sum, mx) % mod) % mod;
		ans = (ans + dp2(p + 1, sum + a[p], max(mx, a[p])) % mod ) % mod;
		return hasmem[p][sum][mx] = ans;
	}
	
	int qsum(int l, int r)
	{
		return s[r] - s[l - 1];
	}
	
	/*void build_st()
	{
		int t = log2(n);
		for(int j = 1; j <= t; j++)
		{
			for(int i = 1; i + (1 << j) - 1 <= n; i++)
				st[i][j] = max(st[i][j - 1], 
				st[i + 1 << (j - 1)][j - 1]);
		}
	}*/
	
	/*int query(int l, int r)
	{
		int k = log2(r - l + 1);
		return max(st[l][k], st[r - (1 << k) + 1][k]);
	}*/
	
	void work2()
	{
		return;
	}
	
	void solve()
	{
		int mx = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			mx = max(mx, a[i]);
			s[i] = s[i - 1] + a[i];
		}
		if(n <= 20)
			printf("%lld", dp1(1, 0, 0));
		else if(mx == 1)
		{
			memset(hasmem, sizeof(hasmem), -1);
			printf("%lld", dp2(1, 0, 0));
		}
		else
			work2();
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	p1::solve();
	return 0; 
} 
