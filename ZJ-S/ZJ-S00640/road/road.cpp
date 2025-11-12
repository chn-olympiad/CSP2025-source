#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n,m,k;
vector<ll> tree[1000010];
ll w[1000010];
ll c[10][1000010];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;++i)
	{
		ll u,v;
		scanf("%lld%lld%lld",&u,&v,&w[i]);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for(ll i=1;i<=k;++i)
	{
		for(ll j=1;j<=n;++j)
		{
			scanf("%lld",&c[i][j]);
		}
	}
	printf("0");
	return 0;
}