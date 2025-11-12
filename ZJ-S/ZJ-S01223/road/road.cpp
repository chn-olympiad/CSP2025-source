#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,bcj[10001];
struct st
{
	int u,v,w;
}e[100001];
bool tnt(st x,st y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0)cout<<0;return 0;
	for(int i=1;i<=n;i++)
	{
		bcj[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,tnt);
	for(int i=1;i<=m;i++)
	{
		if(bcj[e[m].u]==bcj[e[m].v])
		{
			continue;
		}
		else
		{
			ans+=e[i].w;
			for(int j=1;j<=n && j!=e[i].v;j++)
			{
				if(bcj[e[i].v]==bcj[j])
				{
					bcj[j]=bcj[e[i].u];
				}
			}
			bcj[e[i].v]=bcj[e[i].u];
		}
	}
	cout<<ans;
}
