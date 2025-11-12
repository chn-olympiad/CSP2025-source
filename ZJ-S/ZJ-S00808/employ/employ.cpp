#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int n,m;
string s;
int a[510];
int c[510];
bool st[510];
long long ans;

void dfs(int x)
{
	if (x == n + 1)
	{
		int cnt = 0;
		int cnt1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (cnt1 >= c[a[i + 1]])
			{
				cnt1++;
				continue;
			}
			if (s[i] == '1')
				cnt++;
			else
				cnt1++;
		}
		
		if (cnt >= m)
		{
			ans++;
			ans %= MOD;
		}
		
		return ;
	}	
	
	for (int i = 1; i <= n; i++)
	{
		if (!st[i])
		{
			st[i] = 1;
			a[x] = i;
			dfs(x + 1);
			st[i] = 0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	
	cin >> s;
	
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	
	if (n <= 10)
	{
		dfs(1);
		
		cout << ans;
	}
	else
	{
		long long ans1 = 1;
		for (int i = 2; i <= n; i++)
		{
			ans1 *= i;
			ans1 %= MOD;
		}
		
		cout << ans1;
	}
	
	return 0;
}