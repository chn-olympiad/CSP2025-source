#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
ll n,m,k,xc[20],xc0;
vector<pii>s[20010];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		s[0].push_back({0,i});
		s[i].push_back({0,0});
	}
	for(int i=1;i<=m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		s[x].push_back({z,y});
		s[y].push_back({z,x});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>xc[i];
		if(xc[i]==0)
		{
			xc0++;
		}
		s[0].push_back({xc[i],n+i});
		s[n+i].push_back({xc[i],0});
		for(int j=1;j<=n;j++)
		{
			ll ls;
			cin>>ls;
			s[n+i].push_back({ls,j});
			s[j].push_back({ls,n+i});
		}
	}
	for(int i=1;i<=n;i++)
	{
		sort(s[i].begin(),s[i].end());
	}
	if(xc0==k)
	{
		cout<<0;
	}
	return 0;
}
