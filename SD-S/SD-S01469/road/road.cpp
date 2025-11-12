#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
#define int long long
const int N=1e4+10;
vector<pair<int,int> > a[N];
int n,m,k;
int c[15][N];
int ans=1<<30;
bool vis[N];
int lowbit(int x)
{
	return x&-x;
}
void dfs(int x,int y,int cnt,int id)
{
	if(y==n)
	{
		ans=min(ans,cnt);
		return ;
	}
	if(vis[x]||cnt>=ans)
		return ;
	int l=a[x].size();
	vis[x]=1;
	for(int i=0;i<l;i++)
	{
		int w=a[x][i].second;
		for(int j=id;j>0;j-=lowbit(j))
			w=min(w,c[lowbit(j)][x]+c[lowbit(j)][a[x][i].first]);
		dfs(a[x][i].first,y+1,cnt+w,id);
	}
	vis[x]=0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			scanf("%lld",&c[i][j]);
	for(int i=0;i<(1<<k);i++)
	{
		int x=0;
		for(int j=i;j>0;j-=lowbit(j))
			x+=c[lowbit(j)][0];
		memset(vis,0,sizeof vis);
		dfs(1,1,x,i);
	}
	printf("%lld",ans);
	return 0;
}
/*
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
freopen(".in","w",stdin);
freopen(".out","r",stdout);
feropen(".in","r",stdin);
feropen(".out","w",stdout);
I'm luogu uid748678.
Maybe it's my last year in CSP/NOIP.
Hope everything goes best.
*/
