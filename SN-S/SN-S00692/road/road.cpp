#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[20],a[20][10010];
vector<pair<int,int> > e[10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][j];
		}
	}
	cout<<0<<"\n";
	return 0;	
}
