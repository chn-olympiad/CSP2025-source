#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,sum[N],a[N],ans,last=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=last;j<=i;j++)
		{
			if((sum[i]^sum[j-1])==k)
			{
				ans++;
				last=i+1;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
