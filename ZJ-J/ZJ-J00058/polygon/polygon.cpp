#include<bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int n, a[5005], ans = 0;

long long f( int xx )
{
	long long cnt = 1;
	for( int i = n; i >= n - xx + 1; i -- )
	{
		cnt = cnt * i;
		cnt %= ( long long )( Mod );
	}
	for( int i = 1; i <= xx; i ++ )
	{
		cnt /= i;
		cnt %= ( long long )( Mod );
	}
	return cnt;
}
void dfs( int ix, int len, int now, int cnt, int maxx )
{
	if( now > cnt ) return ;
	if( now == cnt ) if( len > maxx * 2 ) ans = ( ans + 1 ) % Mod;
	for( int i = ix + 1; i <= n; i ++ ) dfs( i, len + a[i], now + 1, cnt, max( maxx, a[i] ) );
}

int main()
{
	
	freopen( "polygon.in", "r", stdin );
	freopen( "polygon.out", "w", stdout );
	
	cin >> n;
	for( int i = 1; i <= n; i ++ ) cin >> a[i];
	
	sort( a + 1, a + 1 + n );
	
	if( n <= 20 )
	{
		for( int i = 3; i <= n; i ++ ) dfs( 0, 0, 0, i, 0 );
	
		cout << ans;
	}else 
	{
		long long res = 0;
		for( int i = 3; i <= n; i ++ )
		{
			res += f( i );
			res %= ( long long )( Mod );
		}
		cout << res;
	}
	
	
	return 0;
}
