#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
bool is1 = 1;
int biao[505];
int n;
int ans;
int a[5500];
void dfs(int sum, int now, int maxn)
{
	int d = 0;
	if (sum > maxn * 2)
	{
		d += 1;
	}
	if (sum >= maxn * 2)
	{
		d += biao[now - 1];
		d %= mod;
		//cout << sum << " " << now << " " << maxn << " " << d << endl;
		ans += d;
		ans %= mod;
		return ;
	}
	//else
	//{
		for (int i = now - 1; i >= 1; i--)
		{
			dfs(sum + a[i], i, maxn); 
		}
	//}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	biao[1] = 1;
	for (int i = 2; i <= 50; i++)
	{
		biao[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			biao[i] *= 2;
			biao[i] %= mod;
		}
		biao[i] -= 1;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
			is1 = false;
	}
	if (is1 == 1)
	{
		ans = biao[n];
		int jian = n * (n - 1) / 2;
		ans -= jian;
		ans -= n;
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--)
	{
		dfs(a[i], i, a[i]);
	}
	cout << ans;
	return 0;
}
