#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, m;
string s;

int c[505];
int cnt = 0, f = 0;

long long ans = 0;

int a[15], vis[15];
void dfs(int x)
{
	if (x == n + 1)
	{
		int cnt1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i - 1] == '0')
				cnt1++;
			else if (cnt1 >= c[a[i]])
				cnt1++;
		}
		
		if (n - cnt1 >= m)
			ans++;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			a[x] = i;
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	
	cin >> s;
	
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(1);
	
	cout << ans;
	
	return 0;
}