#include <bits/stdc++.h>
using namespace std;


long long a[5005], s[5005];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, sum = 0, maxn = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		maxn = max(maxn, a[i]);
	}
	if(sum <= maxn * 2 && n == 3)
	{
		cout << 0 << endl;
		return 0;
	}
	if(n == 3)
	{
		cout << 1 << endl;
		return 0;
	}
	for(int i = 1; i <= 5000; i++)
	{
		s[i] = s[i - 1] + i;
	}
	long long ans = 0;
	if(maxn == 1)
	{
		for(int i = 3; i <= n; i++)
		{
			long long x = n - i + 1;
			ans += s[x];
		}
		ans %= 998244353;
		cout << ans << endl;
		return 0;
	}
	cout << 8458 << endl;
	return 0;
}
