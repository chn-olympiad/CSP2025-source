#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5010],qian[5010];
void dfs(long long he,long long cnt,long long now_)
{
	if(cnt>=3)
	{
		if(he>a[now_]*2)
		{
			ans++;
			ans%=998244353;
		}
	}
	for(int i=now_+1;i<=n;i++)
	{
		dfs(he+a[i],cnt+1,i);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i+2<=n;i++)
	{
		dfs(a[i],1,i);
	}
	printf("%lld",ans);
	return 0; 
}
