// 4pts
// 4 分就 4 分，那咋了 
#include <iostream>
#define big long long
using namespace std;
const big mod = 998244353;
big n,m,dif[504],sum,c[504],num;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(big i = 1;i <= n;i++)
	{
		scanf("%1lld",dif+i);
		sum += dif[i];
	}
	for(big i = 1;i <= n;i++)
	{
		scanf("%lld",c+i);
		num += (c[i] != 0);
	}
	if(n == m)
	{
		if(num < m) printf("0\n");
		else
		{
			big ans = 1;
			for(big i = 1;i <= n;i++) ans = (ans*i)%mod;
			printf("%lld",ans);
		}
		return 0;
	}
	return 0;
}
