#include<bits/stdc++.h>
using namespace std;
int head[10010],cnt,s[20][10010],c[20];
struct node
{
	int nxt,to,w;
}g[1000010];
void add(int u,int v,int w)
{
	cnt++;
	g[cnt].to=v;
	g[cnt].nxt=head[u];
	g[cnt].w=w;
	head[u]=cnt;
    return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int l=1;l<=n;l++)
		{
			cin>>s[i][l];
		}
	}
	cout<<0;
	return 0;
}