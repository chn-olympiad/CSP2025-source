#include <stdio.h>
int n,sum;
int main()
{
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
	{
		sum=sum+n-i;
	}
	printf("%d",sum);
	return 0;
}
