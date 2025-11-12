#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int to,f,val;
};
vector<node>v[10000];
int ans=0;
int vis[10090];
bool dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(vis[v[x][i].to]==0)
		{
			vis[v[x][i].to]=1;
			ans+=v[x][i].val;
			dfs(v[x][i].to);
		}
	}
}
int main()
{
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	dfs(1);
	cout<<ans;
	return 0;
}
