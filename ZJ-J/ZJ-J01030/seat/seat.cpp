#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int x[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				a[i][j]=++cnt;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				a[i][j]=++cnt;
			}
		}
	}
	int y=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>x[i];
		if(i==1)y=x[i];
	}
	sort(x+1,x+n*m+1,cmp);
	for(int k=1;k<=n*m;k++)
	{
		if(x[k]==y)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(a[i][j]==k)
					{
						cout<<j<<" "<<i;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
