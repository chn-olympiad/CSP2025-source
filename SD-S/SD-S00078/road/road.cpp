#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100,M=1e6+10;
int n,m,q;
struct Edge
{
	int u,v,w;
}e[M],good[M];
int p[N];
inline int find(int x) {return p[x]==x?x:p[x]=find(p[x]);}
inline bool cmp(Edge a,Edge b){return a.w<b.w;}
int tot;
int a[20][N];
int b[20];
bool flag[N];
long long ans;

int cnt;
inline long long solve()
{
	long long res=0;
	for(int i=1;i<=n+q;i++) p[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(u>n&&(!flag[u-n])) continue;
		if(find(u)!=find(v))
		{
			p[find(u)]=find(v);
			res+=w;
		}
	}
	return res;
}

void dfs(int x,long long sum)
{
	if(x==q+1)
	{
		ans=min(ans,solve()+sum);
		return ;
	}
	flag[x]=false;
	dfs(x+1,sum);
	flag[x]=true;
	dfs(x+1,sum+b[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n+q;i++) p[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v))
		{
			p[find(u)]=find(v);
			good[++tot]=e[i];
			ans+=w;
		}
	}
	memset(e,0,sizeof(e)); 
	for(int i=1;i<=tot;i++) e[i]=good[i];
	cnt=tot;
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		{
			e[++cnt]={i+n,j,a[i][j]};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	dfs(1,0);
	cout<<ans;
	return 0;
}

















