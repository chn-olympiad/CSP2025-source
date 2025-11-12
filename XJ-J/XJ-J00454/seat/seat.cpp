#include<bits/stdc++.h>
using namespace std;
int a[1010],v[1010][1010];
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
	int tmp=a[1];
	int tot=0;
	sort(a+1,a+1+(n*m),greater<int>());
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				v[i][j]=a[++tot];
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				v[i][j]=a[++tot];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(v[i][j]==tmp)
			{
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
