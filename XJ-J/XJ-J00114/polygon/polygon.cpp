#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5005], n, maxx = -1, sum, l, r, m, m1, m2, ans, cnt, cnt1, ans1;
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxx = max(maxx, a[i]);
		sum += a[i];
	}
	if (n <= 3)
	{
		if (n == 3 && sum > maxx * 2)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	sort (a + 1, a + n + 1);
	if (n % 2 == 0)
	{
		m1 = n + 1;
		m2 = n / 2;
		m = m1 * m2;
	}
	else
	{
		m1 = n + 1;
		m2 = n - 1;
		m2 /= 2;
		m = m1 * m2;
		m = m + m2 + 1;
	}
	if (maxx = 1)
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
		{
			ans *= 2;
			ans = ans % 998244353;
		}
		ans -= m;
		ans -= 1;
		ans %= 998244353;
		cout << ans;
		return 0;
	}
	ans = 1;
	cnt = 1;
	cnt1 = 1;
	sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt1 *= i;
		cnt1 %= 998244353;
	}
	for (int i = n - 2; i >= 1; i--)
	{
		maxx = a[n];
		for (int j = n; j >= i; j--)
		{
			sum += a[j];
		}
		if (sum > maxx)
		{
			for (int j = 2; j <= n - i + 1; j++)
			{
				cnt *= j;
				cnt %= 998244353;
			}
			ans1 = cnt1;
			ans1 /= cnt;
			int cnt11 = cnt1 - cnt;
			ans1 /= cnt11;
			ans1 %= 998244353;
			ans += ans1;
			ans %= 998244353;
		}
	}
	cout << ans;
	return 0;
 } 
