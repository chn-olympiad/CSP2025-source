#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int f[11000];
struct edge
{
	int u;
	int v;
	int w;
}e[1100000]; 
void build()
{
	for(int i=1;i<=n;++i)
		f[i]=i;
	return;
}
int find(int x)
{
	if(f[x]=x)return x;
	return f[x]=find(f[x]);
}
void join(int x,int y)
{
	f[f[x]]=f[y];
	return;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
long long kruskal()
{
	long long ans=0;
	int nd=1,idx=0;
	sort(e+1,e+n+1,cmp);
	while(nd<n)
	{
		++idx;
		if(find(e[idx].u)!=find(e[idx].v))
		{
			nd++;
			join(e[idx].u,e[idx].v);
			ans+=e[idx].w;
		}	
	}
	return ans;
}
int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	cout<<kruskal();
	return 0;
}
