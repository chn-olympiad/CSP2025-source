#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[500005];
const long long mod=998244353;
long long ans;
long long maxn=-1e18;
long long num;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);	
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n==3)
	{
		maxn=max(max(a[1],a[2]),a[3]);
		ans=a[1]+a[2]+a[3];
		if(ans>2*maxn)
			printf("1");
		else
			printf("0");
	}
	else
		printf("0");
	return 0;
}//200pts+

