#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, a[5100], f[5100], ans;
//5001 和大于 5001 没有区别！！ 
vector <int> vc;
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", a + i);
	}
	sort(a + 1, a + 1 + n);
	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = a[i] + 1; j <= 5001; j++)
		{
			//j > a[i]
			ans += f[j];
			ans %= mod;
		}
		for(int j = 5001; j >= 0; j--)
		{
			int now = a[i] + j;
			if(now > 5001)
			{
				now = 5001;
			}
			f[now] += f[j];
			f[now] %= mod;
		}
	}
	cout << ans;
}
