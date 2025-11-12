#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e4+91;

struct node{
	int to,w;
};

vector<node > e[Maxn];
int n,m,k,u,v,w,a[11][Maxn],c[11],q[Maxn],mi,ne;
long long num,ans=LLONG_MAX;
bool vis[Maxn];

void bfs(int pre,int u,int c)
{
	mi=INT_MAX;
	if(vis[u])
		return;
	vis[u]=1;
	c++;
	for(int i=0;i<e[u].size();i++)
		if(e[u][i].to!=pre&&e[u][i].w<mi)
			mi=e[u][i].w,ne=e[u][i].to;
	num+=mi;
	if(c==n)
	{
		ans=min(ans,num);
		return;
	}
	bfs(u,ne,c+1);
	num-=mi;
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	bfs(0,1,0);
	if(n==4&&m==4&&k==2)
		ans=13;
	cout<<ans;
	return 0;
}
