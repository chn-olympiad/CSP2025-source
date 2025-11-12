#include<bits/stdc++.h>
using namespace std;
//OK
int n,m,ming,wei;//wei指的是线性的位置 
int a[10010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	ming=a[1];
	sort(a+1,a+n*m+1,cmp);
	wei=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==ming)
		{
			wei=i;
			break;
		}
	}
	if(m%2==0)
	{
		for(int i=1;i<=m/2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[(i-1)*2*n+j]==ming)
				{
					printf("%d %d",(i-1)*2+1,j);
					return 0;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(a[(i-1)*2*n+n+j]==ming)
				{
					printf("%d %d",i*2,n+1-j);
					return 0;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=m/2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[(i-1)*2*n+j]==ming)
				{
					printf("%d %d",(i-1)*2+1,j);
					return 0;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(a[(i-1)*2*n+n+j]==ming)
				{
					printf("%d %d",i*2,n+1-j);
					return 0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[n*(m-1)+i]==ming)
			{
				printf("%d %d",m,i);
				return 0;
			}
		}
	}
	return 0;
 } 
