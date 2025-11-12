#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int cnt[1010],f[1010];
struct node
{
	int v,w,t;
}vv[1010][1010];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
map<int,int> mp;
int find(int x)
{
	if(x==f[x])
	{
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y)
{
	f[find(y)]=find(x);
}
void dfs(int x)
{
	sort(vv[x]+1,vv[x]+1+cnt[x],cmp);
	for(int i=1;i<=cnt[x];i++)
	{
		if(find(vv[x][i].v)!=find(x))
		{
			merge(x,vv[x][i].v);
			ans+=vv[x][i].w;
			if(mp[abs(x-i)*(x+i)]==0)
			{
				ans-=vv[x][i].t;
				mp[abs(x-i)*(x+i)]=1;
			}
			dfs(vv[x][i].v);
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		++cnt[v];
		++cnt[u];
		vv[v][cnt[v]].v=u;
		vv[u][cnt[u]].v=v;
		vv[v][cnt[v]].w=w;
		vv[u][cnt[u]].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		int w,u;
		cin>>w;
		for(int j=1;j<=n;j++)
		{
			cin>>u;
			++cnt[i];
			++cnt[u];
			vv[i][cnt[i]].v=j;
			vv[j][cnt[j]].v=i;
			vv[i][cnt[i]].w=u+w;
			vv[j][cnt[j]].w=u+w;
			vv[i][cnt[i]].t=w;
			vv[j][cnt[j]].t=w;
		}
	}
	dfs(1);
	cout<<ans;
}