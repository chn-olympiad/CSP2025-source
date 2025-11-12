#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int b[101][101];
int a[1000001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	int flag=0;
	int l=1;
	for(int i=1;i<=n*m;i++)
	{
		if(flag==0)
		{
			b[1][l]=a[i];
			i++;
			int u=1;
			while(u+1<=n)
			{
				b[++u][l]=a[i];
				i++;
			}
			l++;
			flag=1;
		}
		if(flag==1)
		{
			b[n][l]=a[i];
			i++;
			int u=n;
			while(u-1>=1)
			{
				b[--u][l]=a[i];
				i++;
			}
			l++;
			i--;
			flag=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
//			printf("%d ",b[i][j]);
			if(b[i][j]==cnt)
			{
				printf("%d %d",j,i);
				return 0;
			}
		}
//		printf("\n");
	}
	return 0;
}
