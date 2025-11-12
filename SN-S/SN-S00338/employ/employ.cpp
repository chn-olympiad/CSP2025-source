#include <stdio.h>
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	long long sum=1;
	scanf("%d",&n);
	for(;n>0;n--)
	{
		sum=sum*n;
		sum=sum%998244353;
	}
	printf("%d",sum);
	return 0;
}
