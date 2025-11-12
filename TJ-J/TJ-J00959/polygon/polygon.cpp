#include <bits/stdc++.h>
using namespace std;

double MAX_TIME = 0.995;
const long long MOD = 998244353;

long long n, a[5005], ans = 0;

void dfs(int i, long long maxn, int c, int len)
{
	if (i > n)
	{	
		
		if (c >= 3)
		{
			if (len > 2 * maxn)	ans++;
			ans %= MOD;
		}
		return;
	}
	if ((double)clock() / CLOCKS_PER_SEC > MAX_TIME) 
	{
		cout << ans;
		exit(0);
	}
	dfs(i + 1, maxn, c, len);
	maxn = max(maxn, a[i]);
	dfs(i + 1, maxn, c + 1, len + a[i]);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n <= 20)
	{
		dfs(1, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
