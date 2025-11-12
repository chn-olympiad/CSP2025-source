#include <stdio.h>
int a[105];
int sum[205];
int z=1;
int n,m;
int x;
int b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	b=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=m*n;j++)
		{
			if(a[j]>sum[i])
			{
				sum[i]=a[j];
				x=j;
			}
		}
		a[x]=0;
	}
/*	for(int i=1;i<=n*m;i++)
	{
		printf("%d ",sum[i]);
	}*/
	for(int i=1;i<=n*m;i++)
	{
		if(sum[i]==b)
		{
			x=i;
			break;
		}
	}
	for(int i=1;i<=m;)
	{
		if(x>n)
		{
			x=x-n;
			i++;
		}
		else if(i%2==0)
		{
			printf("%d %d",i,n-x+1);
			return 0;
		}
		else
		{
			printf("%d %d",i,x);
			return 0;
		}
	}
	return 0; 
}
