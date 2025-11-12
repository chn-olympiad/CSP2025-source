#include<bits/stdc++.h>
using namespace std;
struct way
{
	int u,v,w;
} w[11000002];
int n,m,k,c,fa[11000002];
bool cmp(way x,way y)
{
	return x.w<y.w;
}
int find(int x)
{
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i].u>>w[i].v>>w[i].w;
	}
	for(int j=n+1;j<=n+k;j++)
	{
		cin>>c;
		for(int d=1;d<=n;d++)
		{
			cin>>w[m+d].w;
			w[m+d].u=j,w[m+d].v=d;
		}
	}
	m=m+(n*k);
	sort(w+1,w+1+m,cmp);
	for(int i=1;i<=m;i++) cout<<w[i].u<<' '<<w[i].v<<' '<<w[i].w<<'\n';
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int sum=0,cnt=0; m=1;
	while(cnt!=(n-1+k))
	{
	    int u=find(fa[w[m].u]),v=find(fa[w[m].v]);
		if(u!=v)
		{
		    u=v;
		    cout<<w[m].u<<' '<<w[m].v<<'\n';
		    sum+=w[m].v; cnt++;
		}
		m++;
	}
	cout<<sum<<'\n';
	return 0;
}
