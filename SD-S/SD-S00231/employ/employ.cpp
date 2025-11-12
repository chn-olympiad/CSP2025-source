#include<iostream>
using namespace std;
int n,m;
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		ans=ans%998244353;
		ans=(ans*i)%998244353;
	}
	printf("%lld",ans);
	return 0;
}
