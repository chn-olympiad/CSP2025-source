#include<bits/stdc++.h>
using namespace std;
int a[510],c[510],n,m;
char s[510];
bool vis[510];
long long ans;
void dfs(int x)
{
	if(x==n+1)
	{
		int cnt=0,cnt1=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[a[i]])
			{
				cnt++;
				continue;
			}
			if(s[i]=='1')
			{
				cnt1++;
			}
			else
			{
				cnt++;
			}
		}
		if(cnt1>=m)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			a[x]=i;
			vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
