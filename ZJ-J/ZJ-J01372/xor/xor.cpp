#include<bits/stdc++.h>
using namespace std;
bool f;
long long n,k,a[500010],cnt,sum[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(a[i]==1)
			cnt++;
		if(a[i]>1)
			f=1;
		sum[i]=sum[i-1]^a[i];
	}
	if(!f)
	{
		printf("%lld",cnt);
		return 0;
	}
	cnt=0;
	long long x=1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=x+1;j<=i;j++)
		{
			long long t=sum[i]^sum[j-1];
			if(t==k)
			{
				x=i;
				cnt++;
				break;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}
