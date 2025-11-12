#include <stdio.h>
int n,m;
int c,b;
int a[5005];
int main()
{
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	if(n<3)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==3)
	{
		m=a[1];
		if(m<a[2])
		{
			m=a[2];
		}
		if(m<a[3])
		{
			m=a[3];
		}
		if(m*2<a[1]+a[2]+a[3])
		{
			printf("1");
			return 0;
		}
		else
		{
			printf("0");
			return 0;
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		a=1;
		for(int j=1;j<=n-i;j++)
		{
			b=a+i;
		}
	}*/
	return 0;
}
