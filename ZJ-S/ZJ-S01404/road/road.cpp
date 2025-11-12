#include<bits/stdc++.h>
#define N 10015
#define M 1000005
#define int long long
#define ll long long
using namespace std;
int n,m,k,u[M],v[M],w[M],ans,sum,SUM,a[11],dis[11][N];
void Add(int d)
{
	for(int i=1;i<=n;++i)
	{
		++m;
		u[m]=(ll)i;v[m]=(ll)d+n;w[m]=(ll)dis[d][i];
	}
}
void Delate(int d)
{
	m=(ll)m-n;
}
int fa[N];
int Find(int d)
{
	if(d!=fa[d])fa[d]=Find(fa[d]);
	return fa[d];
}
int U,V;
void solve()
{
	for(int i=1;i<=n+k;++i)fa[i]=i;
	pair<int,pair<int,int> >b[m+1];
	int x=n+SUM;
	for(int i=1;i<=m;++i)
		b[i].first=w[i],b[i].second.first=u[i],b[i].second.second=v[i];
	sort(b+1,b+1+m);
	for(int i=1;i<=m;++i)
	{
		U=b[i].second.first,V=b[i].second.second;
		if(U>V)swap(U,V);
		Find(U);
		Find(V);
		if(fa[U]!=fa[V])
		{
			--x;
			sum=(ll)sum+b[i].first;
			fa[Find(V)]=fa[Find(U)];
		}
		if(x==1)return;
	}
}
int XXXX;
int Min(int XX,int YY)
{
	return (ll)(XX<YY?(ll)XX:(ll)YY);
}
void dfs(int d)
{
	if(d>k)
	{
		XXXX=sum;
		solve();
		ans=Min(ans,sum);
		sum=XXXX;
		return;
	}
	Add(d);
	sum=(ll)sum+a[d];++SUM;
	dfs(d+1);
	Delate(d);
	sum=(ll)sum+a[d];--SUM;
	dfs(d+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%lld",a+i);
		for(int j=1;j<=n;++j)
			scanf("%lld",&dis[i][j]);
	}
	ans=1000000000000000000;
	dfs(1);
	printf("%lld",ans);
	return 0;
}
