#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
const int MOD = 998244353;
#define ll long long
bool vis[5010];
ll ans = 0;
void dfs(int now, int sum, int Max, int num)
{
//	cout << now << " " << sum << " " << Max << " " << num << endl;
	if (num >= 3 && sum > 2*Max)
	{
		ans++;
		ans %= MOD;
	}
	if (now == n)
		return;
	for (int i = now+1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(i, sum+a[i], max(Max, a[i]), num+1);
			vis[i] = 0;
		}
	}
 	return;
}
ll C(int a, int b)
{
	ll k = 1;
	for (int i = 1; i <= b; i++)
	{
		k = k * (a-i+1) / i;
	}
	return k;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 1)
			flag = true;
	}
	if (!flag)
	{
		ll res = 0;
		for (int i = 3; i <= n; i++)
			res += C(n, i), res %= MOD;
		cout << res << endl;
		return 0;
	}
	dfs(0, 0, -1e9, 0);
	cout << ans << endl;
	return 0;
}


