#include<bits/stdc++.h>
using namespace std ;
const int MX = 1e6 ;
int u[MX + 10],v[MX + 10],w[MX + 10],c[12][10010] ;
int main()
{
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0) ;
	int n,m,k,i,j,ans ;
	cin >> n >> m >> k ;
	for (i = 1 ; i <= m ; i++)
	{
		cin >> u[i] >> v[i] >> w[i] ;
	}
	for (i = 1 ; i <= k ; i++)
	{
		for (j = 1 ; j <= n ; j++)
		{
			cin >> c[i][j] ;
		}
	}
	sort(w + 1,w + m + 1) ;
	for (i = 1 ; i < n ; i++)
	{
		ans += w[i] ;
	}
	cout << ans << '\n' ;
	return 0 ;
}

