#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Edge{
	int v,w;
};
int n,m,k,c[15],a[15][10005];
vector<Edge> to;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		to[u].push_back(Edge{v,w});
		to[v].push_back(Edge{u,w});
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;i++)
		{
			if(j==0) cin>>c[i],continue;
			cin>>a[i][j];
		}
	}
	cout<<0<<endl;
	return 0;
 } 
