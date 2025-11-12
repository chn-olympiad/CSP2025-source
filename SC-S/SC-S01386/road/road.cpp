#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=2e6+5;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &rhs)const{return w<rhs.w;}
}e[M];
int n,m,k,cnt;
int c[M],fa[M<<1],sz[M<<1];
int find(int x){return (x==fa[x])?x:fa[x]=find(fa[x]);}
ll ans=0;
void Kruskal()
{
	int sum=0;
	for(int i=1,u,v,w,fu,fv;i<=m&&sum<cnt-1;i++)
	{
		u=e[i].u,v=e[i].v,w=e[i].w;
		fu=find(u),fv=find(v);
		if(fu==fv) continue;
		if(sz[fu]>sz[fv]) swap(fu,fv);
		sum++;
		fa[fu]=fv,sz[fv]+=sz[fu],ans+=w;
//		cout<<u<<' '<<v<<' '<<w<<'\n';
	}
}
void kruskal(int S)
{
	ll ans2=0;int sum=n-1+__builtin_popcount(S);
	for(int i=1;i<=n+k*2;i++) fa[i]=i,sz[i]=1;
	int u2,v2;
	for(int i=1,u,v,w,fu,fv;i<=m&&sum;i++)
	{
		u=e[i].u,v=e[i].v,w=e[i].w;
		if(u>n) u2=(u-n+1)/2;
		if(v>n) v2=(v-n+1)/2;
		if(u>n&&!(S&(1<<u2-1))) continue;
		if(v>n&&!(S&(1<<v2-1))) continue;
		fu=find(u),fv=find(v);
		if(fu==fv) continue;
		if(sz[fu]>sz[fv]) swap(fu,fv);
		sum++;
		fa[fu]=fv,sz[fv]+=sz[fu],ans2+=w;
//		cout<<u<<' '<<v<<' '<<w<<' ';
//		if(u>n) cout<<u2<<' ';
//		if(v>n) cout<<v2<<' ';
//		cout<<'\n';
	}
//	cout<<S<<' '<<ans2<<'\n';
	ans=min(ans,ans2); 
}
void solve()
{
	ans=1e18;
	for(int S=0;S<(1<<k);S++) kruskal(S);
	printf("%lld",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),cnt=n;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	bool flag=0,flag2=1;
	for(int i=1,x;i<=k;i++)
	{
		scanf("%d",&c[i]);
		flag|=c[i],flag2=1;
		cnt+=2;
		e[++m]={n+i*2-1,n+i*2,c[i]};
		for(int j=1;j<=n;j++) scanf("%d",&x),flag2&=x,e[++m]={n+i*2-1,j,x};
		flag|=flag2;
	}
	sort(e+1,e+1+m);
	if(flag) return solve(),0;
	for(int i=1;i<=n+k*2;i++) fa[i]=i,sz[i]=1;
	Kruskal();
	printf("%lld",ans);
	return 0;
}