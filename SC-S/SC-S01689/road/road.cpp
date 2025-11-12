#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e4+1,maxm=2200001;
int n,m,k,id;
int c[11],h[maxn+10],nxt[maxm],e[maxm],w[maxm];
int a[11][maxn];
void add(int u,int v,int c)
{
	e[id]=v;
	w[id]=c;
	nxt[id]=h[u];
	h[u]=id++;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++)
	{
		ll w;
		int u,v;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	bool f=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i])
		{
			f=1;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			add(n+i,j,a[i][j]);
			add(j,n+i,a[i][j]);
			if(a[i][j])
			{
				f=1;
			}
		}
	}
	if(!f)
	{
		cout<<0;
		return 0;
	}
	
	return 0;
}