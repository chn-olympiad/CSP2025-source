#include<bits/stdc++.h> 
using namespace std;
int n,m,a[1005]={0},p,x=1,y=1,b[1005][1005]={0};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+m*n,cmp);
	for(int u=1;u<=m*n;u++)
	{
		if(x%2!=0)
		{
			b[x][y]=a[u];
			y++;
		}
		else
		if(x%2==0)
		{
			b[x][y]=a[u];
			y--;
		}
		if(y==1)
		{
			b[x][y]=a[u+1];
			u++;
			x++;
		}
		if(y==n)
		{
			b[x][y]=a[u+1];
			u++;
			x++;
		}
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==p)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
