#include <bits/stdc++.h>
#define int long long 
using namespace std;

int MOD = 998244353;
int n, m;
string str;
int passday[600];
int wait[600];
int ans = 0;
int used[100];
int situation[100];

int check()
{
	int getin = 0;
	int left = 0;
	for (int i = 0; i < n; i++)
	{
		if (passday[i] == 0 || left >= wait[situation[i]])
		{
			left++;
		}
		else
		{
			getin++;
		}
	}
	if (getin >= m) ans++;
	return 0;
}

int dfs(int k)
{
	if (k == n)
	{
		check();
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			situation[k] = i;
			dfs(k + 1);
			situation[k] = 0;
			used[i] = 0;
		}
	}
	return 0;
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> str;
	bool allok = 1;
	for (int i = 0; i < n; i++)
	{
		passday[i] = str[i] - '0';
		if (passday[i] == 0) allok = 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> wait[i];
		if (wait[i] == 0) allok = 0;
	}
	
	if (m == n && allok)
	{
		int ansss = 1;
		for (int i = 1; i <= n; i++)
		{
			ansss *= i;
			ansss %= MOD;
		}
		cout << ansss << endl;
		return 0; 
	}
	
	sort(wait, wait + n);
	dfs(0);
	cout << ans % MOD << endl;
	return 0;
}
//
