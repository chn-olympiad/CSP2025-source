#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+20;
ll n,m,k;
ll v[N];
vector<pair<ll,ll> > g[N];
ll bfs()
{
	ll ret=0,fl=0;
	priority_queue<pair<ll,ll> > que;
	v[1]=1;
	que.push({0,1});
	while(que.size())
	{
		ll p=que.top().second;
		if(p<=n) fl++;
		ret+=(-1*que.top().first);
		if(fl==n) return ret;
		que.pop();
		for(pair<ll,ll>x : g[p] )
		{
			ll p2=x.first;
			if(v[p2]==1) continue;
			que.push({-1*x.second,p2});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		ll a,b,w;
		cin>>w>>a>>b;
		g[a].push_back({b,w});
		g[b].push_back({a,w});
	}
	for(ll i=1;i<=k;i++)
	{
		ll w;
		cin>>w;
		for(ll j=1;j<=n;j++)
		{
			ll x;
			cin>>x;
//			g[n+i][j]=w+x;
//			g[j][n+i]=w+x;
			g[j].push_back({n+i,w+x});
			g[n+i].push_back({j,w+x});
		}
	}
	cout<<bfs();
	return 0;
}

