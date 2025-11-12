#include<bits/stdc++.h>
#define inf LLONG_MAX
using namespace std;
typedef long long ll;
typedef __int128 llong;
const ll N=1e6+6;
struct road
{
	ll u,v,w;
}r[N];
ll n,m,k,a[15][N],c[N],ans;
map<ll,ll> mp;
void init()
{
	for(int i=0;i<=N;i++)
	{
		mp[i]=i;
	}
}
ll find(ll x)
{
	if(mp[x]==x)
	{
		return x;
	}
	mp[x]=find(mp[x]);
	return mp[x];
}
void add(ll x,ll y)
{
	ll xx=find(x);
	ll yy=find(y);
	if(xx!=yy)
	{
		mp[x]=mp[y];
	}
}
bool cmp(road u,road b)
{
	return u.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&r[i].u,&r[i].v,&r[i].w);
	}
	ll l=n;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=l;j++)
		{
			scanf("%lld",&a[i][j]);
			r[++n]={i,j,a[i][j]};
		}
	}
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		cerr<<find(r[i].u)<<" "<<find(r[i].v)<<"\n";
		if(find(r[i].u)!=find(r[i].v))
		{
			ans+=r[i].w;
			add(r[i].u,r[i].v);
		}
	}
	cout<<ans;
	return 0;
}

