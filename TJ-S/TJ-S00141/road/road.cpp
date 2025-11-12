#include<bits/stdc++.h>
using namespace std;
int fa[10005],n,m,k;
long long ans;
struct node{
	int u,v,w;
};
vector<node> e;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w,c;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>w;
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(node t:e)
	{
		int x=find(fa[t.u]),y=find(fa[t.v]);
		if(x!=y){
			fa[x]=y;
			ans+=t.w;
		}
	}
	cout<<ans;
	return 0;
}
