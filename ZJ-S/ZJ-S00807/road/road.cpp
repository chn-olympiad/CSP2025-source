#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int f[15005];
int p;
struct node
{
	int u,v,w;
}e[1500005];
int c[15][1505];
int findfather(int x)
{
	if(f[x]==x) return x;
	return f[x]=findfather(f[x]);
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
void kruskal()
{
	int sum=0;
	for(int i=1;i<=m;++i)
	{
		if(f[e[i].u]==f[e[i].v]) continue;
		sum++;
		f[e[i].u]=findfather(f[e[i].v]);
		ans+=e[i].w;
		if(sum==n-1) return;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;++i) 
	{
		cin>>c[i][0];
		for(int j=1;j<=n;++j) cin>>c[i][j];
	}
	kruskal();
	cout<<ans<<"\n";
	return 0;
}
