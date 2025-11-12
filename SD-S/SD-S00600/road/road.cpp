#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v,w;
};
vector<edge> mp[10010];
int t[20][10010];
long long res;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		mp[u].push((edge){v,w});
		mp[v].push((edge){u,w});
		res+=w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>t[i][j];
		}
	}
	cout<<res;
	return 0;
}
