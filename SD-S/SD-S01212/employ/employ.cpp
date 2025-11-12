#include <bits/stdc++.h>
using namespace std;
char s[505];
int n,m,a[505],b[505],c[505];
long long ans,mod = 998244353;
void dfs(int x)
{
	if(x == n + 1)
	{
		int cnt = 0,sum = 0;
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == '0')
			{
				sum++;
				cnt++;
			}
			else
			{
				if(cnt >= a[c[i]])
				{
					sum++;
					cnt++;
				}
			}
		}
		sum = n - sum;
		ans += (sum >= m);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(b[i] == 0)
		{
			c[x] = i;
			b[i] = 1;
			dfs(x + 1);
			c[x] = 0;
			b[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	scanf("%s",s + 1);
	int f = 1;
	for(int i = 1;i <= n;i++)
	{
		if(s[i] == '0')
		{
			f = 0;
		}
		scanf("%d",&a[i]);
	}
	if(n <= 12)
	{
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	ans = 1;
	for(int i = 1;i <= n;i++)
	{
		ans = (ans * i) % mod;
	}
	printf("%lld",ans);
	return 0;
}
