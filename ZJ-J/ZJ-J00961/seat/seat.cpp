#include<bits/stdc++.h>
using namespace std;
int n,m,a[1619],x,y,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	scanf("%d",&a[1]);
	x=a[1];
	for(int i=2;i<=n*m;i++) scanf("%d",&a[i]);
	sort(a+1,a+n*m+1);
	y=1;l=n*m+1;
	for(int i=1;i<=m;i++)
	{
		if(y==1)
		for(int j=1;j<=n;j++)
		{
			l--;
			if(a[l]==x)
			{
				printf("%d %d",i,j);
				return 0;
			}
			y=n;
		}
		else
		for(int j=n;j>=1;j--)
		{
			l--;
			if(a[l]==x)
			{
				printf("%d %d",i,j);
				return 0;
			}
			y=1;
		}
	}
	return 0;
}
