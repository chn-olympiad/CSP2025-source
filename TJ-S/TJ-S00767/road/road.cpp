#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int to,bu,tb;
};
vector<node>rd[10010];
int ans=INT_MAX;
int vis[10010];
void dfs(int x,int add,int fa)
{
	for(int i=1;i<=n+k;i++)
	{
		cout<<vis[i]<<' ';
	}
	cout<<'\n';
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
			flag=1;
	}
	if(flag==0)
	{
		cout<<add<<"--\n";
		ans=min(ans,add);
		return;
	}
	
	for(int i=0;i<rd[x].size();i++)
	{
		if(rd[x][i].to==fa)
			continue;
		if(vis[rd[x][i].to]==1)
			continue;
		vis[rd[x][i].to]=1;
		if(rd[x][i].tb!=0)
		{
			int stay=rd[x][i].tb;
			rd[x][i].tb=0;
			dfs(rd[x][i].to,add+rd[x][i].bu+stay,x);
			rd[x][i].tb=stay;
		}
		else
		{
			dfs(rd[x][i].to,add+rd[x][i].bu,x);
		}
		vis[rd[x][i].to]=0;
		
	}
	
}
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int mx=-1;
	for(int i=1;i<=m;i++)
	{
		int u,v,s;
		cin>>u>>v>>s;
		mx=max(mx,u);
		mx=max(mx,v);
		rd[u].push_back(node{v,s,0});
		rd[v].push_back(node{u,s,0});
	}
	for(int i=1;i<=k;i++)
	{
		int tobuy;
		cin>>tobuy;
		for(int j=1;j<=n;j++)
		{
			int buy;
			cin>>buy;
			rd[mx+i].push_back(node{j,buy,tobuy});
			rd[j].push_back(node{mx+i,buy,tobuy});
		}
	}
	vis[1]=1;
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}

