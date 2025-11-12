#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans=0;
int n,a[5050],mx=-1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
    }
    sort(a+1,a+n+1);
    if(n<3||mx==0)
    {
    	printf("0");
    	return 0;
	}
    else if(n==3)
    {
    	if(a[1]+a[2]>a[3])
    	{
    		printf("1");
		}
		else
		{
			printf("0");
		}
		return 0;
	}
	else if(mx==1)
	{
		for(int i=3;i<=n;i++)
		{
			long long s=1;
			long long p=1;
			for(int j=0;j<i;j++)
			{
				s*=(1LL*(n-j)%mod);
				p*=(1LL*(j+1)%mod);
			}
			ans=1LL*(s/p)%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
