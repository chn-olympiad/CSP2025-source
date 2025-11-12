#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5010],n;
long long ans;
void dfs(int k,int maxn,int sum,int choose)
{
	if(k==n+1)
	{
		if(choose<3)
			return;
		if(sum>maxn*2)
			ans=(ans+1)%mod;
		return;
	}
	dfs(k+1,maxn,sum,choose);
	dfs(k+1,max(maxn,a[k]),sum+a[k],choose+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
