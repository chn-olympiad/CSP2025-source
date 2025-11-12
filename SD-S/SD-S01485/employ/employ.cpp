#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int MOD = 998244353;
int n, m, ans, flag;
int a[N], p[N], vis[N], w[25] = {1}; 
string s;
void dfs(int x, int len, int nc, int np)
{
	vis[x] = 1;
	if(nc >= a[x]) nc++;
	else if(s[len] == '1') np++;
	else nc++;
	if(np >= m)
	{
		ans = (ans + w[n - len]) % MOD;
		vis[x] = 0;
		np--, nc--;
		return;
	}
	if(len == n)
	{
		vis[x] = 0;
		np--, nc--;
		return;
	}
	for(int i = 1; i <= n; ++i)
	{
		if(vis[i] == 0)
		{
			dfs(i, len + 1, nc, np);
		}
	}
	np--, nc--;
	vis[x] = 0;
}
void sub1_solve()
{
	for(int i = 1; i <= n; ++i)
	{
		dfs(i, 1, 0, 0);
	}
	cout << ans;
}
void sub2_solve()
{
	ans = 1;
	int x = n;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] == 0) --x;
	}
	for(int i = 2; i <= x; ++i)
	{
		ans = ans * i % MOD;
	}
	cout << ans;
}
void sub3_solve()
{
	ans = 1;
	int x = n;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] == 0) --x;
	}
	for(int i = 2; i <= x; ++i)
	{
		ans = ans * i % MOD;
	}
	cout << ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for(int i = 1; i <= 20; ++i) w[i] = w[i - 1] * i % MOD; 
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i)
	{
		if(s[i] == '0')
		{
			flag = 1;
			break;
		}
	}
	if(m == 1) sub3_solve(); 
	else if(!flag) sub2_solve();
	else sub1_solve();
	return 0;
}

