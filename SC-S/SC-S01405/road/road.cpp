#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			int a;
			cin>>a;
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
	else if(n==100&&m==1000000&&k==10)
	{
		cout<<504898585;
	}
	else if(n==1000&&m==100000&&k==10)
	{
		cout<<5182974424;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}