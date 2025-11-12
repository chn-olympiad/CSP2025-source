#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
struct node{
	ll to;
	ll len;
};
vector<ll> ma[N];
ll st[N];
ll bb[N][N];
ll n,m,k;
bool used[N];
bool vis[N][N];
ll ans=0;
void dj(ll st)
{
	for(auto v:ma[st])
	{
		
	}
}
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	while(m--)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		node a,b;
		a.len=z,a.to=y;
		b.len=z,b.to=x;
		ma[x].push_back(y);
		ma[y].push_back(x);
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>st[i];
		for(ll j=1;j<=n;j++)
		{
			cin>>bb[i][j];
	    }
    }
    if(k==0)
    {
    	for(ll i=1) 
	}
	return 0;
}
