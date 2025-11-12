#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
struct node
{
	int u,v,w;
}d[1000005];
int f[1000005];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
		f[i]=i;
	for(int i=1;i<=m;++i)
		cin>>d[i].u>>d[i].v>>d[i].w;
	sort(d+1,d+1+n,cmp);
	for(int i=1;i<=m;++i)
	{
		int x=find(d[i].u),y=find(d[i].v);
		if(x!=y)
		{
			f[x]=y;
			ans+=d[i].w;
		}
	}
	for(int i=1;i<=k;++i)
	{
		vector<int> nc;
		for(int j=1;j<=n+1;++j)
		{
			int a;
			cin>>a;
			nc.push_back(a);
		}
	}
	cout<<ans;
	return 0;
}