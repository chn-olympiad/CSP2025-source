#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long n,a[10000],ans,mod = 998244353;

void dfs(int dis,int sum)
{
	if(dis == n+1) return;
	dfs(dis+1,sum);
	dfs(dis+1,sum+a[dis]);
	if(dis >= 3 && sum > a[dis]) ans ++;
	ans %= mod;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	long long sx = 0;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		sx += a[i];
	}
	sort(a+1,a+n+1);
	if(sx == n)
	{
		for(int i = 3;i <= n;i ++)
		{
			long long x = 1,y = 1;
			for(int k = 1;k <= i;k ++)
			{
				x = (x*k)%mod,y = (y*(n-k+1))%mod;
			}
			ans = (ans+y/x)%mod;
		}
	}
	else
	{
		dfs(1,0);
	}
	cout << ans; 
	return 0;
}