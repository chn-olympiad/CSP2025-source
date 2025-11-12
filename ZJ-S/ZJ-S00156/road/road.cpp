#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,p[10015],a[15];
struct e{
	int u,v,w;
	bool operator <(e const &E) const{
		return E.w>w;
	}
};
int Find(int x)
{
	if(x==p[x]) return x;
	return p[x]=Find(p[x]);
}
void q(int u,int v)
{
	int U=Find(u);
	int V=Find(v);
	p[U]=V;
}
vector <e> E;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) p[i]=i; 
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			E.push_back({n+i,j,w});
		}
	}
	sort(E.begin(),E.end());
	int ans=0;
	for(e x:E)
	{
		if(Find(x.u)!=Find(x.v))
		{
			ans+=x.w;
			q(x.u,x.v);
		}
	}
	cout<<ans;
	return 0;
}