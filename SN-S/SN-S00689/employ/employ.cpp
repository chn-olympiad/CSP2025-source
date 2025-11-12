#include <bits/stdc++.h>

using namespace std;

constexpr int N = 505, mod = 998244353;
int n, m, v[N], c[N], ans = 0;
bool vis[N];
char s[N];

void dfs(int id)
{
	if (n < id)
	{
		int cnt0 = 0, cnt1 = 0;
		for (int i = 1; i <= n; ++ i)
		{
			if (s[i] == '0')
			{
				++ cnt0;
				continue;
			}
			
			int now = v[i];
			if (c[now] <= cnt0)
			{
				++ cnt0;
			}
			else
			{
				++ cnt1;
			}
		}
		
		if (m <= cnt1)
		{
			++ ans;
			if (mod <= ans)
			{
				ans -= mod;
			}
		}
		return;
	}
	
	for (int i = 1; i <= n; ++ i)
	{
		if (vis[i])
		{
			continue;
		}
		vis[i] = true, v[id] = i;
		dfs(id + 1);
		vis[i] = false;
	}
}

int main()
{
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; ++ i)
	{
		cin >> c[i];
	}
	
	dfs(1);
	
	cout << ans << endl;
	return 0;
}
