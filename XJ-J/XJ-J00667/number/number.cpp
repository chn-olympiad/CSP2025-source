#include<cstdio>
#include<stdio.h>
int a[1000];
int main()
{
	freopen("numder.in","r","stdin");
	freopen("number.out","w","stdout");
	int m=0;
	char q;
	scanf("%d",&q);
	for(int i=0; ;i++)
	{
		
		if(q/10<='z'&&q/10>='a')
		{
			++i;
		}
		a[i]=q%10;
		q/=10;
		if(q==0)
		{
			break;
		}
		m++;
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(a[i]>a[j])
			{
				q=a[i];
				a[i]=a[j];
				a[j]=q;
			}
		}
	}
	for(int i=0;i<=m;i++)
	{
		printf("%d",a[i]);
	}
	fclose(stdio);
	fclose(stdout);
	return 0;
} 
