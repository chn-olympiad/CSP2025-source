#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const long long mod = 998244353;
long long a[5005], s[5005], ans = 0;
void dfs(int step, int top, int sum)
{
	if (sum + s[top - 1] - s[step - 1] <= a[top]) return ;
    if (sum > a[top])
	{
		long long mul = 1;
		for (int i = step; i < top; ++i)
		{
			mul = mul * 2 % mod;
		}
		ans = (ans + mul) % mod;
		return ;
	}
    dfs(step + 1, top, sum);
	dfs(step + 1, top, sum + a[step]);
}

int main()
{
    freopen("polygon.in", "r". stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
    	cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
    {
    	s[i] = s[i - 1] + a[i];
	}
	if (a[n] == 1)
	{
		long long cnt = 0;
		long long mul1 = 1, mul2 = 1;
		for (long long i = n; i >= 1; --i)
		{
			++cnt;
			mul1 *= i;
			mul2 *= cnt;
			if (cnt >= 3) ans = (ans + mul1 / mul2) % mod;
		}
		cout << ans << endl;
		return 0;
	}
	if (n <= 500)
	{
		for (int i = 3; i <= n; ++i)
		{
			dfs(1, i, 0);
		}
		cout << ans << endl;
		return 0;
	}
    return 0;
}
