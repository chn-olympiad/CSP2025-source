#include<bits/stdc++.h>
using namespace std;
int n,m,k;int sum=0;
struct node
{
	int to,w;
};
vector<node>G[10010];
int c[15],kw[15][10010];


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		sum+=w;
	}
	cout<<sum<<endl;
	
	return 0;
}
