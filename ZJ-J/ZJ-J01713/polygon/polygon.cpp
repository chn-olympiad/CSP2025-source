#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5010, MOD = 998244353;
int n, ans = 0, cnt = 0;
int a[N];
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = true;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			flag = false;
		}	
	} 
	if(flag)
	{
		for(int i = 2; i <= n - 1; i ++)
		{
			for(int j = n; j >= (n - i); j --)
			{
				if(!ans) ans = 1;
				ans = ans * j;
			}
			for(int j = 2; j <= i; j ++) ans /= j;
			cnt += ans, ans = 0;
		}
		cout << cnt % MOD;
		return 0;
	}
	else
	{
		sort(a + 1, a + n + 1);
		int maxn = a[n];
		if(n == 3)
		{
			if(a[1] + a[2] > a[3]) cout << 1;
			else cout << 0;
		}
		else
		{
			for(int w = 3; w <= n; w ++)
			{
				for(int i = 1; i <= w - 1; i ++)
				{
					for(int j = i; j <= w - 1; j ++)
					{
						for(int k = i; k <= j; k ++)
						{
							ans += a[k];
						}
						if(ans > maxn) cnt ++;
						ans = 0;
					}
				}
			}
			cout << cnt;
		}
		return 0;
	}
	return 0;
}
