#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
struct node
{
	int st,en;
	ll w;
}e[2000010];
ll w,f[2010][2010],fa[40010],ans,c[40010],d[40010],z;
int n,m,cnt,fst,fen,t,x,y,ct;
int cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>t;
	if(t==0)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y>>z;
			if(x!=y)
			{
				e[++cnt].st=x;
				e[cnt].en=y;
				e[cnt].w=z;
			}
		}
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=cnt;i++)
		{
			fst=find(e[i].st);
			fen=find(e[i].en);
			if(fst!=fen)
			{
				fa[fen]=fst;
				ans+=e[i].w;
				ct++;
				if(ct==n-1) break;
			}
		}
		cout<<ans;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		f[x][y]=min(f[x][y],min(f[y][x],z));
		f[y][x]=min(f[y][x],min(f[x][y],z));
	}
	for(int i=1;i<=t;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>d[j];
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(j!=k)
					f[j][k]=min(f[j][k],c[i]+d[j]+d[k]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&f[i][j]!=inf)
			{
				e[++cnt].st=i;
				e[cnt].en=j;
				e[cnt].w=f[i][j];
			}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		fst=find(e[i].st);
		fen=find(e[i].en);
		if(fst!=fen)
		{
			fa[fen]=fst;
			ans+=e[i].w;
			ct++;
			if(ct==n-1) break;
		}
	}
	cout<<ans;
	return 0;
}