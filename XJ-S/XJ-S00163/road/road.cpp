#include<iostream>
using namespace std;
int a[10005]={0};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j,ans=0;
	cin>>n>>m>>k; 
	for(i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	for(i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	cout<<ans;
	return 0;
}
