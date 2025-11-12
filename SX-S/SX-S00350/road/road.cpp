#include <bits/stdc++.h>
#define ll long long
#define N 1000100
using namespace std;

ll n,m,k,c[10][N];
vector<ll>vec[N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		vec[v].push_back(u);
		vec[u].push_back(v);
	}
	for(int i=1;i<=k;++k)
	{	
		for(int j=0;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=n;i++)
			{
				while(1)
				{
					int a[10000];
				}
			}
		}
	}
	return 0;
}
