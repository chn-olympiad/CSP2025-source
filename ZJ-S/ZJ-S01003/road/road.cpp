#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[100100],a[11][10001],fa[10100],p[20],d,ans,minn=LONG_LONG_MAX,ansp;
int find(int x)
{
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
struct city
{
	int u;
	int v;
	int w;
}ff[1000100],f[1000100];
bool cmp(city x,city y)
{return x.w<y.w;}
void dfs(int x,int pp)
{
	if(x>k)
	{
		int mm=m,d=0,ans=0;
		for(int i=1;i<=mm;i++) f[i].u=ff[i].u,f[i].v=ff[i].v,f[i].w=ff[i].w;
		for(int i=1;i<=pp;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mm++;
				f[mm].u=n+p[i];
				f[mm].v=j;
				f[mm].w=a[p[i]][j];
			}
			ans+=c[p[i]];
			//cout<<ans<<" ";
		}
		sort(f+1,f+mm+1,cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=mm;i++)
		{
			
			int fx=find(f[i].u),fy=find(f[i].v);
			if(fx!=fy)
			{
				fa[fx]=fy;
				d++;
				//cout<<ans<<" ";
				ans+=f[i].w;
				if(d==n+k-1) break;
			}
		}
		//cout<<'\n';
		minn=min(minn,ans);
		return ;
	}
	if(pp<k)
	{
		p[pp+1]=x;
		dfs(x+1,pp+1);
	}
	dfs(x+1,pp);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	bool flag=true;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>ff[i].u>>ff[i].v>>ff[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) flag=false;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(flag)
	{
		for(int i=1;i<=m;i++) f[i].u=ff[i].u,f[i].v=ff[i].v,f[i].w=ff[i].w;
		for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		{
			m++;
			f[m].u=n+i;
			f[m].v=j;
			f[m].w=a[i][j];
		}
		sort(f+1,f+m+1,cmp);
		int ans=0,d=0;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			
			int fx=find(f[i].u),fy=find(f[i].v);
			if(fx!=fy)
			{
				fa[fx]=fy;
				d++;
				ans+=f[i].w;
				if(d==n+k-1) break;
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<minn;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
