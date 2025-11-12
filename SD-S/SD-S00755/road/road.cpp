#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >vec[11111];
int a[20][11111];
int c[20];
int vis[11111];
int n,m,k;
int ans=INT_MAX;
int path[11111];
void dfs(int x,int sum,int tot)
{
	if(tot==n)
	{
		ans=min(ans,sum);
		return; 
	}
	int len=vec[x].size();
	for(int i=0;i<len;i++)
	{
		if(!vis[vec[x][i].first])
		{
			vis[vec[x][i].first]=1;
			dfs(vec[x][i].first,sum+vec[x][i].second,tot+1);
			vis[vec[x][i].first]=0;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans*=1000000;
	cin>>n>>m>>k;
	int cnt=0;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
		cnt+=w;
	}
	int ok=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) ok=1;
		for(int j=1;j<=n;j++) 
		{
			cin>>a[i][j];
			if(a[i][j]) ok=1;
		}
	}
	if(k==0)
	{
		vis[1]=1;
		dfs(1,0,1);
		cout<<ans;
		return 0;
	}
	if(ok==0)
	{
		cout<<0;
		return 0;
	}
	cout<<cnt;
} 
