#include <bits/stdc++.h>
using namespace std;
const int N=1e4+50;
struct node{
	int u,v,w,j;
};
int vis[N];
struct cmp
{
	bool operator()(node a,node b)
	{
		return a.w+vis[a.j]>b.w+vis[b.j];
	}
};
int n,m,k,cnt,fa[N];
bool ck[N];
long long ans=0;
priority_queue<node,vector<node>,cmp>q;
int fd(int x)
{
	if(fa[x]==x)return fa[x];
	else return fa[x]=fd(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int _=1,u,v,w;_<=m;_++)
	{
		cin>>u>>v>>w;
		q.push((node){u,v,w,0});
	}
	for(int j=n+1;j<=n+k;j++)
	{
		cin>>vis[j];
		for(int i=1,x;i<=n;i++)
		{
			cin>>x;
			q.push((node){j,i,x,j});
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	while(cnt<n)
	{
		int u=q.top().u,v=q.top().v,w=q.top().w+vis[q.top().j];
		vis[q.top().j]=0;
		q.pop();
		int f1=fd(u);
		int f2=fd(v);
		if(u<=n&&!ck[u])cnt++;
		if(v<=n&&!ck[v])cnt++;
		if(f1!=f2)
		{
			fa[f1]=fa[f2];
			ck[u]=ck[v]=1;
			ans+=w;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
