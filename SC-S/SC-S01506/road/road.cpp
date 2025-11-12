#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u,v,w,vis[12],ans,fa[110002],t[12],tot1;
vector<int> ve[12];
pair<int,pair<int,int> > a[1000002],b[110002],bb[10002];
int fid(int x)
{
	if(x!=fa[x]) fa[x]=fid(fa[x]);
	return fa[x];
}
bool rzgz(int u,int v)
{
	int x=fid(u),y=fid(v);
	if(x!=y) fa[x]=y;
	else return 0;
	return 1;
}
void work()
{
	int cnt=0;
	tot1=n-1;
	for(int i=1;i<=n;i++) b[i]=bb[i];
	for(int i=1;i<=k;i++)
	{
		if(vis[i]==1)
		{
//			cout<<i<<" ";
			cnt+=t[i];
			for(int j=0;j<n;j++)
				b[++tot1]={ve[i][j],{j+1,n+i}};
		}
	}
	if(tot1==n-1) return;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(b+1,b+1+tot1);
	for(int i=1;i<=tot1;i++)
		if(rzgz(b[i].second.first,b[i].second.second))
			cnt+=b[i].first;
	ans=min(ans,cnt);
//	cout<<cnt<<"\n";
}
void dfs(int x)
{
	if(x==k+1)
	{
		work();
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[i]={w,{u,v}};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>t[i];
		for(int j=1,v;j<=n;j++)
		{
			cin>>v;
			ve[i].push_back(v);
		}
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++)
	{
		if(rzgz(a[i].second.first,a[i].second.second))
		{
			b[++tot1]=a[i],ans+=a[i].first;
			bb[tot1]=b[tot1];
		}
	}
//	cout<<ans<<"\n";
	dfs(1);
	cout<<ans;
	return 0;
}
/*
只能拿到80pts qwq
我们先对原图进行一次最小生成树，再用2^k*nk的时间复杂度
枚举乡村城市化及答案，最后求最小即可。 
*/