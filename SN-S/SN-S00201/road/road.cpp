#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
vector< pair<ll,ll> >g[10003];
ll a[12][10003],c[12];
ll sum=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		sum+=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	}
	cout << sum;
	return 0;
//	else
//	{
//		for(int i=1;i<=n;i++)
//		{
//			if(a[])
//		}
//	}
}
//15:01 bu hui qwq
//18:20 fang qi le QwQ 
