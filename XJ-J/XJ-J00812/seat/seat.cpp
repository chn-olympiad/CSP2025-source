#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,k,nums,num[105],a[105][105],x,y;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>num[i];
	}
	nums=num[1];
	sort(num+1,num+n*m+1);
	for(i=0;i<=n+1;i++)
	{
		a[0][i]=-1;
		a[m+1][i]=-1;
	}
	for(i=0;i<=m+1;i++)
	{
		a[i][0]=-1;
		a[i][n+1]=-1;
	}
	x=1;
	y=1;
	for(i=n*m;i>=1;i--)
	{
		if(y%2==0 and x==1)
		{
			a[x][y]=num[i];
			y++;
			i--;
		}
		else if(y%2==0)
		{
			a[x][y]=num[i];
			x--;
		}
		if(x==n and y%2==1)
		{
			a[x][y]=num[i];
			y++;
		}
		else if(y%2==1)
		{
			a[x][y]=num[i];
			x++;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==nums)
			{
				cout<<j<<' '<<i;

			}
		}
	}
	return 0;
}
