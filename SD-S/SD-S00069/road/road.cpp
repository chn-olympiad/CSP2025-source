#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const int inf=1e9+7;
ll n,m,k;
ll u[1000005],v[1000005],w[1000005];
ll c[N];
ll a[15][N];
ll fa[N],ans;
//vector<int>
struct node{
	ll u,v,w;
}b[1000005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
ll find(ll x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);	
} 
void solve1()
{
	for(int i=1;i<=m;i++)
	{
		b[i].u=u[i];
		b[i].v=v[i];
		b[i].w=w[i];
	}
	sort(b+1,b+m+1,cmp);
	ll tot=0;
	for(int i=1;i<=m;i++)
	{
		if(tot==n-1) break;
		ll fx=find(fa[b[i].u]);
		ll fy=find(fa[b[i].v]);
		if(fx!=fy)
		{
			fa[fx]=fa[fy];
			tot++;
			ans+=b[i].w;
		}
	}
	cout<<ans;
}
void solve2()
{
	for(int i=1;i<=m;i++)
	{
		b[i].u=u[i];
		b[i].v=v[i];
		b[i].w=w[i];
	}
	sort(b+1,b+m+1,cmp);
	ll tot=0;
	for(int i=1;i<=m;i++)
	{
		if(tot==n-1) break;
		ll fx=find(fa[b[i].u]);
		ll fy=find(fa[b[i].v]);
		if(fx!=fy)
		{
			fa[fx]=fa[fy];
			tot++;
			ans+=b[i].w;
		}
	}
	ll st=fa[1];
	for(int i=1;i<=n;i++)
	{
		if(find(fa[i])!=st) 
		{
			ans=1e18;
			return;
		} 
	}
}
ll kur(int cnt)
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(b+1,b+cnt+1,cmp);
	ll an=0,tot=0;
	for(int i=1;i<=cnt;i++)
	{
		if(tot==n) break;
		ll fx=find(fa[b[i].u]);
		ll fy=find(fa[b[i].v]);
		if(fx!=fy)
		{
//			cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<endl;
			fa[fx]=fa[fy];
			tot++;
			an+=b[i].w;
		}
	}
	return an;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	ll sum=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	if(k==0)
	{
		solve1();
		return 0;
	} 
	if(m>=n-1)
	{
		solve2();
	}
	int cnt=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[j].u=u[j];
			b[j].v=v[j];
			b[j].w=w[j];
		}
		for(int j=1;j<=n;j++)
		{
			b[m+j].u=n+k;
			b[m+j].v=j;
			b[m+j].w=a[i][j];
		}
		ans=min(kur(m+n)+c[i],ans);
	}
	cout<<ans;
	return 0;
} 
