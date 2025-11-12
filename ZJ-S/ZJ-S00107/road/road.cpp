#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,ans,res=4e18;
int fr[M<<1],to[M<<1],w[M<<1];
vector<int> e[N];
int a[12][N];
int fa[N+10],sz[N+10];
int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
void kru(int us)
{
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
	for(int i=1;i<=n+k;++i) fa[i]=i,sz[i]=1;
	for(int i=1;i<=(m<<1);++i) p.push({w[i],{fr[i],to[i]}});
	int po=0;
	for(int i=1;i<=k;++i)
		if((us>>i-1)&1)
		{
			po++;
			for(int j=1;j<=n;++j) p.push({a[i][j],{j,n+i}});
		}
	int cnt=0;
	while(cnt<n+po-1)
	{
		int val=p.top().first,v=p.top().second.first,x=p.top().second.second;
		p.pop();
		if(find(v)==find(x)) continue;
		ans+=val,cnt++;
		if(sz[v]<sz[x]) swap(v,x);
		fa[x]=v,sz[v]+=sz[x];
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road1.in","r",stdin);
//	freopen("road1.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,x;i<=m;++i)
	{
		scanf("%lld%lld%lld",&u,&v,&x);
		fr[i<<1]=to[(i<<1)-1]=v,fr[(i<<1)-1]=to[i<<1]=u,w[(i<<1)-1]=w[i<<1]=x;
		e[u].push_back((i<<1)-1),e[v].push_back(i<<1);
	}
	for(int i=1;i<=k;++i)
		for(int j=0;j<=n;++j) scanf("%lld",&a[i][j]);
	for(int i=0;i<(1<<k);++i)
	{
		ans=0;
		for(int j=0;j<k;++j)
			if((i>>j)&1)
				ans+=a[j+1][0];
		kru(i);
		res=min(res,ans);
	}
	printf("%lld\n",res);
	return 0;
}
