#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[510],n,m;
char s[510];
bool came[510];
long long ans;
void dfs(int x,int cnt)
{
	if(x==n+1)
	{
		if(cnt>=m)
			ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(came[i])
			continue;
		came[i]=1;
		if(x-cnt-1<a[i]&&s[x-1]=='1')
			dfs(x+1,cnt+1);
		else
			dfs(x+1,cnt);
		came[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	if(n<=10)
	{
		dfs(1,0);
		printf("%lld",ans);
	}
	else
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*i)%mod;
		printf("%lld",ans);
	}
	return 0;
}
