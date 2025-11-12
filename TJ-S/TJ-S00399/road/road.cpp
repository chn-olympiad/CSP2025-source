#include "bits/stdc++.h"

#define ll long long
#define MAXN 10005
#define MAXM 1000005

using namespace std;

ll n, m, k;
ll u[MAXN], v[MAXN], w[MAXN];
ll a[MAXM][MAXN], c[MAXM];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	for(ll i = 1;i <= n;i ++) cin >> u[i] >> v[i] >> w[i];
	for(ll i = 1;i <= m;i ++) 
	{
		cin >> c[i];	
		for(ll j = 1;j <= n;j ++)
		{
			cin >> a[i][j];
		}
	}
	
	
	return 0;
}
