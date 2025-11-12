#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s[5010];
const int mod=998224353;
long long cnt=0,ma=0;
void dfs(int x,int sum,int ma,int c)
{
	if(x>n)
	{
		if(sum>ma*2&&c>=3)
			cnt=(cnt+1)%mod;
		return;
	}
	dfs(x+1,sum+a[x],max(ma,a[x]),c+1);//дц 
	dfs(x+1,sum,ma,c);//╡╩дц 
}
long long mp(long long x)
{
	long long c=1,a=2;
	while(x)
	{
		if(x%2==1)
			c=(c*a)%mod;
		x/=2,a=(a*a)%mod;
	}
	return c;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ma=max(a[i]*1LL,ma);
	}
	if(ma!=1)	dfs(1,0,0,0);
	else
	{
		for(int i=1;i<=n;i++)
		{
			long long len=n-i;
			cnt=(cnt+(mp(len)-1-len)%mod)%mod;
		}
	}
	printf("%lld",cnt);
	return 0;
}

