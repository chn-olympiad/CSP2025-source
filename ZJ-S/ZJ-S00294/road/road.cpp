#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long n,m,k,c[15],a[15][10005],vis[10005],ans;
vector <pair<int,int>> vs[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,w,v;
		cin>>u>>v>>w;
		vs[u].push_back(make_pair(v,w));
		vs[v].push_back(make_pair(u,w));
	}
	int pq=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) pq=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=0) pq=1;
		}
	}
	if(pq==0)
	{
		cout<<0;
		return 0;
	}
	vis[1]=1;
	int op=1;
	while(1)
	{
		int u=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				u=1;
				break;	
			}
		}
		if(u==0) break;
		int MIN=1e9,id=0;
		for(auto o:vs[op])
		{
			int x=o.first,y=o.second;
			if(vis[x]==1) continue;
			if(MIN>y)
			{
				MIN=y;
				id=x;
			}
		}
		op=id;
		vis[id]=1;
		ans+=MIN;
	}
	cout<<ans;
	return 0;
}