#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int u,v,w;
}edges[10485760];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int n,m,k,fa[10240],book[10240];
int c[16],a[16][10240];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[x]=find(y);
}
void kru(int s)
{
	book[s]=1;
	int tmp=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		if(book[edges[i].u]&&book[edges[i].v]) continue;
		if(find(edges[i].u)==find(edges[i].v)) continue;
		merge(edges[i].u,edges[i].v);
		book[edges[i].u]=1,book[edges[i].v]=1;
		tmp++;
		ans+=edges[i].w;
		if(tmp==n-1)
		{
			cout<<ans;
			break;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",u,v,w);
		edges[i].u=u;
		edges[i].v=v;
		edges[i].w=w;
	}
	int ind,tot;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",a[i][j]);
			if(a[i][j]==0)
				ind=j;
		}
		for(int j=1;j<=n;j++)
		{
			tot++;
			edges[m+tot].u=ind;
			edges[m+tot].v=j;
			edges[m+tot].w=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(edges,edges+m+tot+1,cmp);
	kru(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
