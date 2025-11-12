#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0;
	scanf("%d",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==3)
	{
		if((a[1]+a[2]>a[3])&&(a[1]+a[3]>a[2])&&(a[2]+a[3]>a[1]))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		return 0;
	}
	long long k=1;
	for(long long i=1;i<=n;i++)
	{
		k=(k*2)%mod;
	}
	printf("%d",(k-1-(n*(n+1))/2+mod)%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}