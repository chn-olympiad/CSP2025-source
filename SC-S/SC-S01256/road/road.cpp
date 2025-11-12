#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e6+4;
int n,m,k;
int fa[N],vis[N];
void init()
{
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
}
int getfa(int x)
{
	if(x==fa[x])return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
int a[N],cnt,ans=LONG_LONG_MAX;
struct sd{
	int u,v,w;
}s[N];
void dfs(int nw)
{

	if(nw==n+k+1)
	{
		int d=0;
		for(int i=n;i<=n+k;i++)
		{
			if(vis[i]==1)d+=a[i];
		}
	//	cout<<d<<" ";
		init();
		for(int i=1;i<=cnt;i++)
		{
			int u=s[i].u,v=s[i].v,w=s[i].w;
			int fu=getfa(u),fv=getfa(v);
	//		cout<<u<<" "<<v<<" "<<w<<endl;
			if(fu==fv)continue;
			if(vis[u]==0&&u>n)continue;
			if(vis[v]==0&&v>n)continue;
			fa[fv]=fu;
			
			d+=w;
			if(d>ans)return;
		}
		
	//	cout<<d<<endl;
	//	puts("");
		ans=min(ans,d);
		return;
	}
	vis[nw]=1;
	dfs(nw+1);
	vis[nw]=0;
	dfs(nw+1);
}
bool cmp(sd a,sd b)
{
	return a.w<b.w;
}
main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	cnt=0;
	init();
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		s[++cnt]={u,v,w};
		s[++cnt]={v,u,w};
	}
	for(int i=1;i<=k;i++)
	{
		
		cin>>a[i+n];
		
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			s[++cnt]={i+n,j,w};
			s[++cnt]={j,i+n,w};
		}
	}
//	cout<<cnt<<endl;
	sort(s+1,s+cnt+1,cmp);
	
//	for(int i=1;i<=cnt;i++)cout<<s[i].w<<" "<<s[i].u<<" "<<s[i].v<<endl;
	dfs(n+1);
	cout<<ans;
	return 0;
}//为什么中间两个样例死活过不去
//红温了
//mmp
//卧槽
//开到4e6过了