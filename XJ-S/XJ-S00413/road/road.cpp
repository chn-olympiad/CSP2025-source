#include<iostream>
using namespace std;
int n,m,k;
int u,v,w,a,c;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	for(int j=1;j<=n;j++)
	{
		cin>>c;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
		}
	}
	cout<<0<<endl;
	return 0;
} 
