#include <bits/stdc++.h>
using namespace std;

namespace p1
{
	const int MAXN = 505;
	const int mod  = 998244353;
	int n, m, s[MAXN], c[MAXN];
	int hasmem[MAXN][MAXN];
	string tmp;
	
	int dfs(int p, int sum)
	{
		if(p > n) return 0;
		if(sum == m) return 1;
		if(hasmem[p][sum]) return hasmem[p][sum];
		int ans = dfs(p + 1, sum + 1) % mod;
		ans = (ans + dfs(p + 1, sum) % mod) % mod;
		return hasmem[p][sum] = ans; 
	}
	
	void solve()
	{
		cin >> m >> n;
		cin >> tmp;
		int flag = 1;
		for(int i = 0; i < tmp.size(); i++)
		{
			int si = tmp[i] - '0';
			flag &= si;	
		}	
		for(int i = 1; i <= n; i++) cin >> c[i];
		if(flag)
		{
			cout << dfs(1, 0);
		}
	}	
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	p1::solve();
	return 0;
}
