#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int MAXN = 5e3 + 5;
int n, a[MAXN], ans;

void dfs(int step, int sum, int cnt)
{
	if (step > n) return ;
	if (cnt < 2)
	{
		dfs(step + 1, a[step] + sum, cnt + 1);
		dfs(step + 1, sum, cnt);
		return ;
	}
	if (a[step] < sum)
	{
		ans = (ans + 1) % mod;
		//cout << a[step] << " " << sum + a[step] << endl;
		dfs(step + 1, sum + a[step], cnt + 1);
	}
	else
		dfs(step + 1, sum + a[step], cnt + 1);
	dfs(step + 1, sum, cnt);
	
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n <= 500)
		dfs(1, 0, 0);
	else
	{
		for (int N = 3; N <= n; N++)
		{
			int NN = N - 2;
			ans += ans + (NN + 1) * NN / 2;
		}
	}
	cout << ans;
	return 0;
}
