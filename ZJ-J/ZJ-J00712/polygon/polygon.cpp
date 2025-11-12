#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int MOD=998244353;
int n,a[N],ma;
long long ans;
void dfs(int k,int sum,int maxx,int cnt)
{
	if(k==n+1)
	{
		if(sum>maxx*2&&cnt>=3)
		{
			ans=(ans+1)%MOD;
		}
		return;
	}
	dfs(k+1,sum+a[k],max(maxx,a[k]),cnt+1);
	dfs(k+1,sum,maxx,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
	}
	if(ma==1)
	{
		long long cheng=1,chu=1;
		for(int i=1;i<=2;i++)
		{	
			cheng=(cheng*(n-i+1))%MOD;
			chu=(chu*i)%MOD;
		}
		for(int i=3;i<=n;i++)
		{
			cheng=(cheng*(n-i+1))%MOD;
			chu=(chu*i)%MOD;
			ans=(ans+cheng/chu)%MOD;
		}
	}
	else
	{
		dfs(1,0,0,0);		
	}
	printf("%lld",ans);
	return 0;
}
