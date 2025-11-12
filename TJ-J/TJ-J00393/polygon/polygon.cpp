#include <bits/stdc++.h>

const int MOD = 998244353;

std::vector<int> a;

int n;
int res = 0;

void dfs(int idx, int d, int depth, int sum, int maxn)
{
	if(d == depth)
	{
		if(maxn * 2 < sum)
			res = (res + 1) % MOD;						
	}
	for(int i = idx; i < n; i++)
	{
		dfs(i + 1, d + 1, depth, sum + a[i], std::max(maxn, a[i]));
	}
	return;
}
int main()
{
	std::freopen("polygon.in", "r", stdin);
	std::freopen("polygon.out", "w", stdout);
	
	std::cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	for(int i = 3; i <= n; i++)	
	{
		dfs(0, 0, i, 0, -1);	
	}	
	std::cout << res % MOD << '\n';
	return 0;
}
