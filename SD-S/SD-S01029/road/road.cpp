#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long LL;
const int N=1e4+50,M=1e6+10;
int n,m,k;
int h[N],e[N<<1],ne[N<<1],idx,w[N<<1];
int fa[N];
int fa1[N],fa2[N][15],dis[N],_dis[N][15],vis[15];
int flg1[N],flg2[N];
int dp[N],_id[N];
LL ans,sum;
struct node
{
	int u,v,w;
}roa[M];
LL a[15][N],c[15];
void insert(int u,int v,int c)
{
	e[++idx]=v;
	ne[idx]=h[u];
	h[u]=idx;
	w[idx]=c;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	fa[u]=v;
}
void dfs2(int u,int fat)
{
//	cout<<u<<" ";
	fa1[u]=fat;
	for(int i=h[u];i;i=ne[i])
		if(e[i]!=fat) 
		{
			dis[e[i]]=w[i];
			dfs2(e[i],u);
		}
}
void dfs1(int u,int fat,int dep)
{
//	cout<<"*";
	if(u<=n) dp[u]=a[dep][u],_id[u]=u;
	else dp[u]=2e9+1;
	for(int i=h[u];i;i=ne[i])
		if(e[i]!=fat)
		{
			dfs1(e[i],u,dep);
			if(w[i]>dp[e[i]])
			{
				sum-=w[i]-dp[e[i]];
				if(!flg2[_id[e[i]]]) flg1[_id[e[i]]]=1;
				else flg2[_id[e[i]]]=0;
				flg2[e[i]]=1;
				if(w[i]<dp[u]) dp[u]=w[i],_id[u]=e[i];
			}
			else if(dp[e[i]]<dp[u]) dp[u]=dp[e[i]],_id[u]=_id[e[i]];
		}
//	cout<<dep<<":"<<u<<" "<<dp[u]<<" "<<_id[u]<<" "<<sum<<endl;
}
void dfs(int dep)
{
//	cout<<dep<<" ";
	if(dep==k+1)
	{
		ans=min(ans,sum);
//		for(int i=1;i<=n+k;++i)
//		{
//			cout<<i<<":";
//			for(int j=h[i];j;j=ne[j]) cout<<e[j]<<" ";
//			cout<<endl;
//		}
//		cout<<sum<<" "<<endl;
//		cout<<endl;
//		for(int i=1;i<=k;++i) cout<<vis[i]<<" ";
//		cout<<endl;
		return ;
	}
//	cout<<dep<<" ";
	dfs(dep+1);
	int mi=2e9+1,id;
	LL _sum=sum;
	for(int i=1;i<=n;++i)
		if(mi>a[dep][i]) mi=a[dep][i],id=i;
//	cout<<dep<<" ";
	dfs2(id,0);
	for(int i=1;i<=n+k;++i) fa2[i][dep]=fa1[i],_dis[i][dep]=dis[i];
//	cout<<dep<<" ";
	fa1[id]=n+dep,fa1[n+dep]=0;
//	cout<<dep<<":\n";
//	for(int i=1;i<=k;++i) cout<<vis[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n+k;++i) cout<<fa1[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n+k;++i) h[i]=0;
	idx=0;
	for(int i=1;i<=n+dep;++i)
	{
		if((i<=n||vis[i-n])&&i!=id&&fa1[i]) insert(i,fa1[i],dis[i]),insert(fa1[i],i,dis[i]);
//		if((i<=n||vis[i-n])&&!fa1[i]) cout<<i<<" ";
	}
	for(int i=1;i<=n+dep;++i) dp[i]=2e9+1,flg1[i]=flg2[i]=0;
	sum+=c[dep]+a[dep][id];
	flg1[id]=1;
	dfs1(id,0,dep);
//	cout<<dep<<":\n";
//	for(int i=1;i<=n+k;++i) cout<<flg1[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n+k;++i) cout<<flg2[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n+k;++i) cout<<dp[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n+k;++i) cout<<_id[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n+k;++i) h[i]=0;
	idx=0;
	for(int i=1;i<=n+dep;++i)
	{
		if((i<=n||vis[i-n])&&i!=id&&!flg2[i]&&fa1[i]) insert(i,fa1[i],dis[i]),insert(fa1[i],i,dis[i]);
//		if((i<=n||vis[i-n])&&!flg2[i]&&!fa1[i]) cout<<i<<" ";
		if(flg1[i]) insert(i,n+dep,a[dep][i]),insert(n+dep,i,a[dep][i]);
	}
	vis[dep]=1;
	dfs(dep+1);
	sum=_sum;
	for(int i=1;i<=n+k;++i) fa1[i]=fa2[i][dep],dis[i]=_dis[i][dep];
	for(int i=1;i<=n+k;++i) h[i]=0;
	idx=0;
	vis[dep]=0;
	for(int i=1;i<=n+dep;++i)
	{
		if((i<=n||vis[i-n])&&fa1[i]) insert(i,fa1[i],dis[i]),insert(fa1[i],i,dis[i]);
//		if((i<=n||vis[i-n])&&!fa1[i]) cout<<i<<" "<<dep<<endl;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i) scanf("%d%d%d",&roa[i].u,&roa[i].v,&roa[i].w);
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(roa+1,roa+m+1,cmp);
//	for(int i=1;i<=m;++i) cout<<roa[i].u<<" "<<roa[i].v<<" "<<roa[i].w<<endl;
	for(int i=1;i<=m;++i)
		if(find(roa[i].u)!=find(roa[i].v))
		{
			merge(roa[i].u,roa[i].v);
			insert(roa[i].u,roa[i].v,roa[i].w);
			insert(roa[i].v,roa[i].u,roa[i].w);
			sum+=roa[i].w;
//			cout<<sum<<" ";
		}
//	cout<<"*";
	ans=sum;
//	cout<<ans<<" "; 
//	cout<<ans<<" ";
	dfs2(1,0);
	if(k) dfs(1);
	printf("%lld",ans);
	return 0;
} 
