#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=10005;
ll c[15][N];
struct Edge
{
	ll u,v,w;
	bool operator<(const Edge &rhs){return w<rhs.w;}
};
vector<Edge> E;
ll fa[N];
ll find(ll u){return u==fa[u]?u:fa[u]=find(fa[u]);}
ll kru(ll n)
{
	for(ll i=1;i<=n;i++)fa[i]=i;
	sort(E.begin(),E.end());
	ll res=0,cnt=0;
	for(auto [u,v,w]:E)
	{
		if(cnt==n-1)break;
		ll x=find(u),y=find(v);
		if(x==y)continue;
		fa[x]=y;
		res+=w;
		cnt++;
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m,k;
	cin>>n>>m>>k;
	while(m--)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	bool A=1;
	for(ll i=1;i<=k;i++)
	{
		cin>>c[i][0];
		if(c[i][0]!=0)A=0;
		for(ll j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][j]==0)c[i][n+1]=j;
		}
		if(c[i][n+1]==0)A=0;
	}
	if(A)
	{
		for(ll i=1;i<=k;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				E.push_back({c[i][n+1],j,c[i][j]});
			}
		}
		cout<<kru(n)<<'\n';
		return 0;
	}
	return 0;
}