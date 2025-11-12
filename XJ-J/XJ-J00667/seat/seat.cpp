#include<cstdio>
#include<stdio.h>
int main()
{
	freopen("seat.in","r","stdio");
	freopen("seat.out","w","stdout");
	int n,m;
	scanf("%d%d",&m,&n);
	int a[m][n],b[m*n],p,q;
	for(int i=0;i<m*n;i++)
	{
		scanf("%d",&b[i]);
		q=b[0];
	}
	for(int i=0;i<m*n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(b[j]<b[i])
			{
				p=b[i];
				b[i]=b[j];
				b[j]=p;
			}
		}
	}
	int c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			a[j][i]=b[c];
			c++;
			if(a[j][i]==q)
			{
				printf("%d %d",i+1,j+1);
			}
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
