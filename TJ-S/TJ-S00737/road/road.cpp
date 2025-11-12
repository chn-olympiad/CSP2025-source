#include <bits/stdc++.h>
using namespace std;
int m,n,k;
int a[1000][2];
int b[1000][10000];
int main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	cin>>m,n,k;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=2;j++)
		{
		cin>>a[i][j];
		}
	}
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			cin>>b[i][j];	
		}
	}
	
	return 0;
}
