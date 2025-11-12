#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e4+5,M=2e6+5,K=1030;
inline ll rd()
{
	int f=1;char c;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	ll x=(c^48);
	while(isdigit(c=getchar())) x=x*10+(c^48);
	return x*f;
}
struct node{int u,v;ll w;}e[M];
struct tr{node e[N];}res[K];
inline int cmp(node x,node y){return x.w<y.w;}
ll s,n,m,k,cnt0,ans=1e18,fa[N],tot[K],sum[K],c[11],a[11][N],op,tim;
bool ck[11][N][K];
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
void get(int S,int cnt,int n)
{
	tim+=cnt;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int u=fd(e[i].u),v=fd(e[i].v);ll w=e[i].w;
//		cout<<u<<' '<<v<<' '<<w<<endl;
		if(u!=v)
		{
			res[S].e[++tot[S]]={u,v,w};
			sum[S]+=w,fa[u]=v;
		}
	}
//	cout<<S<<' '<<sum[S]<<endl;
}
void dfs(int S,ll val,int s,int lst)
{
	if(sum[S]>=ans) return ;
	ans=min(ans,sum[S]);
	if(S==((1<<k)-1)) return ;
	for(int i=lst+1;i<k;i++) if((S&(1<<i))==0) 
	{
		cnt0=0;
		for(int j=1;j<=tot[S];j++) e[++cnt0]=res[S].e[j];
		for(int j=1;j<=n;j++) e[++cnt0]={j,s+1,a[i][j]};
		sum[S+(1<<i)]=val+c[i];
		get(S+(1<<i),cnt0,s+1);
		dfs(S+(1<<i),val+c[i],s+1,i);
	}
}
int main()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	s=n=rd(),cnt0=m=rd(),k=rd();
	for(int i=1;i<=m;i++) e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
	get(0,m,n);
	for(int i=0;i<k;i++)
	{
		c[i]=rd();
		for(int j=1;j<=n;j++) a[i][j]=rd();
	}
	dfs(0,0,n,-1);
	cout<<ans;
	return 0;	
} 