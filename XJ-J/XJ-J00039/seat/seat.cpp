#include<bits/stdc++.h>
using namespace std;
int main()
{
	propen("seat.in","r",stdin);
	propen("seat.out","w",stdout);
	int n,m,i,j,a,b[15][15],zd=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin<<a;
		}
	}
	if(a>zd)
	{
		zd=a;
		zd=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<a[i][j];
		}
	}
	return 0;
} 
