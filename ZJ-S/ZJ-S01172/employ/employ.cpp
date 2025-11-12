#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;
const int N = 5e2 + 10;
int n, m, ans;
char s[N];
int a[N], c[N];
bool vis[N];
bool check()
{
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sum >= a[c[i]] || s[i] == '0')
		{
			sum++;
			continue;
		}
		cnt++;
	}
	return cnt >= m;
}
void dfs(int step)
{
	if (step > n)
	{
		if (check()) ans++;
		ans %= MOD;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1, c[step] = i;
		dfs(step + 1);
		vis[i] = 0, c[step] = 0;
	}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 10)
	{
		dfs(1);
		cout << ans << endl;
		return 0;
	}
	if (m == n)
	{
		cout << 0 << endl;
		return 0;
	}
	int k = 1;
	for (int i = 1; i < n; i++)
		k = k * i % MOD;
	if (m == 1)
	{
		int last = 0, cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '1')
			{
				cnt = 0;
				for (int j = 1; j <= n; j++)
					if (a[j] > i)
						cnt++;
				if (cnt > last)
					ans = (ans + cnt * k) % MOD;
				last = n - cnt;
			}	
		}
		cout << ans << endl;
	}
	return 0;
}
