#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10010][10010],ak[10010][20];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		cin>>a[x][y];
	}
	for(int l=1;l<=k;l++)
	{
		for(int j=0;j<=n;j++)
		{
			int x;
			cin>>x;
			ak[j][l]=x;
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int j=1;j<=n;j++)
		{
			a[l][j]+=min(a[l-1][j],a[l][j-1]);
		}
	}
	cout<<a[n][n];
} 
