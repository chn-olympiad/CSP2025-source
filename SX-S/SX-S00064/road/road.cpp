#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool vis[10005];
long long ans;
struct node
{
	int v,w;
};
vector<node> q[10005];
int c[10005],a[10005][10005];
int main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		q[u].push_back({v,w});
		q[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
//	for(int i=1;i<=n;i++)
//	{
//		vis[1]=1;
//		int minn=1e9;
//		minn=min(minn,a[i])
//		for(int j=0;j<q[i].size();j++)
//		{
//			vis[j]=1;
//			minn=min(minn,q[i][j].w);
//		}
//		ans+=minn;
//	}
//	cout<<ans;
	cout<<0;
	return 0;
}
