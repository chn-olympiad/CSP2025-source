#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}

