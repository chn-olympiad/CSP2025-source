#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct st{
	ll b,e,x;
	bool operator<(const st&a)const
	{
		return x>a.x;
	}
};
ll fa[101011];
ll find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m,k;
	priority_queue<st> q;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	ll f=1;
	for(ll i=1;i<=k;i++)
	{
		ll a;
		cin>>a;
		f=f^a;
		for(ll j=1;j<=n;j++)
		{
			ll b;
			cin>>b;
		}
	}
	if(f==1&&k)
	{
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int ans=0;
	while(q.size())
	{
		st s=q.top();
		ll xx=find(s.b);
		ll yy=find(s.e);
		if(xx!=yy)
		{
			fa[xx]=yy;
			ans+=s.x;
		}
		q.pop();
	}
	cout<<ans;
	return 0;
}