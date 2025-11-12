#include <bits/stdc++.h>
using namespace std;

/*namespace p1
{
	const int MAXN = 5e3 + 10; 
	int n, k;
	int a[MAXN];
	int hasmem[MAXN][MAXN];
	int cal(int l, int r)
	{
		if(l == r) return a[l] == k ? 1 : 0;
		int x = a[l];
		for(int i = l + 1; i <= r; i++) x ^= a[i]; 
		return x == k ? 1 : 0;
	}
	
	int dfs(int l, int r)
	{
		if(hasmem[l][r] != -1) return hasmem[l][r];
		int ans = cal(l, r);
		for(int i = l; i <= r - 1; i++)
		{
			int res = 0;
			res += dfs(l, i);
			res += dfs(i + 1, r);
			ans = max(ans, res);
		}
		return hasmem[l][r] = ans;
	}
	 
	void solve()
	{
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		memset(hasmem, -1, sizeof(hasmem));
		printf("%d", dfs(1, n)); 
	}
}*/

namespace p2
{
	const int MAXN = 1e3 + 10; 
	int n, k;
	int a[MAXN];
	int hasmem[MAXN][MAXN];
	int s[MAXN];
	int cal(int l, int r)
	{
		if(l == r) return a[l] == k ? 1 : 0;
		if(l == 1) return s[r] == k ? 1 : 0;
		return (s[r] ^ s[l - 1]) == k ? 1 : 0;
	}
	
	int dfs(int l, int r)
	{
		if(hasmem[l][r] != -1) return hasmem[l][r];
		int ans = cal(l, r);
		for(int i = l; i <= r - 1; i++)
		{
			int res = 0;
			res += dfs(l, i);
			res += dfs(i + 1, r);
			ans = max(ans, res);
		}
		return hasmem[l][r] = ans;
	}
	 
	void solve()
	{
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if(i == 1)
			{
				s[i] = a[i];
				continue;
			}
			s[i] = s[i - 1] ^ a[i];
		}
		memset(hasmem, -1, sizeof(hasmem));
		printf("%d", dfs(1, n)); 
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	p2::solve();
	return 0; 
} 
