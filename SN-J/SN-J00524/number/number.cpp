#include <stdio.h>
char n[1000005];
int m[257];
int x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",n);
	for(int i=0;;i++)
	{
		x=n[i];
		if(x==0)
		{
			break;
		}
		m[x-48]++;
//		printf("%d ",x);
//		printf("%d\n",i);
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=m[i];j++)
		{
			printf("%d",i);
		}
	}
//	printf("%d",m[2]);
	return 0;
}
