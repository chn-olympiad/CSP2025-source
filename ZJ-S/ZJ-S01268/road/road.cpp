#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v;
	long long w;
	friend bool operator < (edge x,edge y)
	{
		return x.w<y.w;
	}
}e[5000005],e1[1000005];
int n,m,sm,k;
long long ans;
long long s[10005],c[55],fa[20005];
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void kruskal(int t)
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int cnt=0;
	long long num=0;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(u>n&&(!((1<<(u-n-1))&t))) continue;
		if(v>n&&(!((1<<(v-n-1))&t))) continue;
		u=find(fa[u]),v=find(fa[v]);
		if(u!=v)
		{
			fa[u]=v; cnt++;
			num+=e[i].w;
			if(num+s[t]>ans) break;
			if(cnt==n+k-1) break;
		}
	}
	ans=min(ans,s[t]+num);
	return;
}
void kruskal1()
{
	sort(e1+1,e1+sm+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0;
	for(int i=1;i<=sm;i++)
	{
		int u=find(e1[i].u),v=find(e1[i].v);
		if(u!=v)
		{
			e[++m]=e1[i];
			cnt++;
			fa[u]=v;
			if(cnt==n) break;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> sm >> k;
	for(int i=1;i<=sm;i++) cin >> e1[i].u >> e1[i].v >> e1[i].w;
	kruskal1();
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			long long x; cin >> x;
			e[++m].u=i+n; e[m].v=j; e[m].w=x;
		}
	}
	sort(e+1,e+m+1);
	for(int i=0;i<(1<<k);i++)
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1))) s[i]+=c[j];
	ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<(1<<k);i++) kruskal(i);
	cout << ans;
	return 0;
}
