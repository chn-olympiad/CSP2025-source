#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, mod = 998244353;
int n, m, s[N], c[N], bj[N];

int dfs(int x, int sum)
{
	if(sum + (n - x + 1) < m) return 0;
	
	if(x == n + 1)
		return 1;
	
	int res = 0, i;
	
	for(i = 1; i <= n; i++)
	{
		if(bj[i]) continue;
		bj[i] = 1;
		if(c[i] > x - 1 - sum && s[x]) res += dfs(x + 1, sum + 1);
		else res += dfs(x + 1, sum);
		bj[i] = 0;
	}
	
	return res % mod;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int i;
	char x;
	cin >> n >> m;
	
	for(i = 1; i <= n; i++)
	{
		cin >> x;
		s[i] = x - '0';
	}
	for(i = 1; i <= n; i++)
		cin >> c[i];
	
	if(n <= 18)
		cout << dfs(1, 0);
	else
	{
		int tmp = 0;
		
		for(i = 1; i <= n; i++)
			tmp += s[i]; 
		
		if(tmp < m)
			cout << 0;
		else
		{
			tmp = 1;
			
			for(i = 1; i <= n; i++)
				tmp = tmp * i % mod;
			
			cout << tmp << " ";	 
		}
	}
	return 0;
}