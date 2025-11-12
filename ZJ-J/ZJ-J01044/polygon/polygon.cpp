#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010];
int sum=0;
const int MOD = 998244353;
void f(int m,int p,int tot,int im)
{
	if(m+1 == im)
	{
//		printf("\n");
		if(tot > a[p-1]*2)
		{
			sum++;
			sum=sum%MOD;
		}
		return;
	}
	for(int i=p;i<=n;++i)
	{
//		printf("%lld ",a[i]);
		f(m,i+1,tot+a[i],im+1);
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;++i)
	{
		f(i,1,0,1);
	}
	printf("%lld",sum);
	return 0;
}
