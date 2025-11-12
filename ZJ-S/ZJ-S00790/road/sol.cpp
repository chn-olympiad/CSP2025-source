#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1.1e4+5,M=1e6+5,K=10;
const ll INF=1e18;
struct dat{int u,v,w,op;}e[M],E[M];
int n,m,cnt,k,fa[N],c[K];
void init(){for(int i=1;i<=n+k;++i)fa[i]=i;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int uni(int u,int v)
{
	if((u=find(u))==(v=find(v)))return 0;
	fa[v]=u;return 1;
}
ll solve(int s)
{
	ll res=0;
	for(int i=0;i<k;++i)if(s>>i&1)res+=c[i];
	init();
	for(int i=1;i<=cnt;++i)if(!~E[i].op||s>>E[i].op&1)
		if(uni(E[i].u,E[i].v))res+=E[i].w;
	return res;
}
void ATRI()
{
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i)cin>>u>>v>>w,e[i]={u,v,w,-1};
	sort(e+1,e+m+1,[=](dat x,dat y){return x.w<y.w;});
	init();
	for(int i=1;i<=m;++i)if(uni(e[i].u,e[i].v))E[++cnt]=e[i];
	for(int i=0;i<k;++i)
	{
		cin>>c[i];
		for(int j=1,w;j<=n;++j)cin>>w,E[++cnt]={n+i+1,j,w,i};
	}
	sort(E+1,E+cnt+1,[=](dat x,dat y){return x.w<y.w;});
	ll ans=INF;
	solve(1);
	for(int s=0;s<1<<k;++s)ans=min(ans,solve(s));
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ATRI();
	return 0;
}