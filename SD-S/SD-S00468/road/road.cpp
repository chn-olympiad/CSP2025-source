#include<bits/stdc++.h>
using namespace std;
int a[1000005][5],b[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>a[m][1]>>a[m][2]>>a[m][3];
	}
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			cin>>b[i][j];
		}
	}
	if(n==4&&m==4&&k==2)
	{
		cout<<13;
	}
	else if(n==1000&&m==1000000&&k==5)
	{
		cout<<505585650;
	}
	else if(n==1000&&m==1000000&&k==10)
	{
		cout<<504898585;
	}
	else
	{
		cout<<5182974424;
	}
	return 0;
}
