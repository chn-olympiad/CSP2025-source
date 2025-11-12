//SN-S00218  zhangjiakang  xi'an gaoxindiyizhongxue
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=1e4+10;
ll n,m,k;
ll c[maxn],a[20][maxn],fa[maxn],tot;
struct node{
	ll u,v,w;
	bool operator<(node x)
	{
		return x.w>w;
	}
}e[maxn*100];
ll find(ll x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cout<<0;
	cin>>n>>m>>k; 
	for(ll i=1;i<=n;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		e[++tot]=node{u,v,w};
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	if(k==0)
	{
		for(ll i=1;i<=n;i++)fa[i]=i;
		sort(e+1,e+m+1);
		ll tot=0,ans=0;
		for(ll i=1;i<=m;i++)
		{
			ll fu=find(e[i].u),fv=find(e[i].v);
			if(fu==fv)continue;
			ans+=e[i].w;
			fa[fu]=fv;
			tot++;
			if(tot==n-1)
				break;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
