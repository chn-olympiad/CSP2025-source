#include<bits/stdc++.h> 
using namespace std ;
#define q_q return 0

const long long N = 1e4 + 10, M = 1e4 + 10, P = 13331, mod = 1e9 + 7 ;

string s[N][2], t[N][2] ;

long long n, q ;

long long a[N][2], b[N] ;

bool flag = true ;

long long qpow( long long a, long long b )
{
	long long ret = 1 ;
	while( b )
	{
		if( b & 1 )	ret = ( ret * a ) % mod ;
		a = a * a % mod ;
		b >>= 1 ;
	}
	return ret ;
}

signed main()
{
	freopen( "replace.in", "r", stdin ) ;
	freopen( "replace.out", "w", stdout ) ;
	
	ios_base::sync_with_stdio( false ) ;
	cin.tie( nullptr ) ;	cout.tie( nullptr ) ;
	
	cin >> n >> q ;
	
	for(long long i=1; i<=n; i++)	cin >> s[i][0] >> s[i][1] ;
	for(long long i=1; i<=n; i++)
	{
		for( auto c : s[i][0] )
			a[i][0] = ( a[i][0] * P + c ) % mod ;
		for( auto c : s[i][1] )
			a[i][1] = ( a[i][1] * P + c ) % mod ;
	}
	
	while( q-- )
	{
		string t1, t2 ;	cin >> t1 >> t2 ;
		t1 = ' ' + t1 ;
		t2 = ' ' + t2 ;
		if( t1.size() != t2.size() )
		{
			cout << 0 << endl ;
			continue ;
		}
		long long ans = 0, hs = 0 ;
		for(long long i=1; i<t1.size(); i++)	b[i] = ( b[i-1] * P + t1[i] ) % mod, hs = ( hs * P + t2[i] ) % mod ;
		for(long long i=1; i<t1.size(); i++)
		{
			for(long long j=1; j<=n; j++)
			{
				if( i + s[j][0].size() - 1 >= t1.size() )	continue ;
				if( ( b[i + s[j][0].size() - 1] - b[i-1] * qpow( P, s[j][0].size() ) % mod + mod ) % mod != a[j][0] )	continue ;
				long long tmp = ( ( ( a[j][1] - a[j][0] ) * qpow( P, i - 1 ) % mod + b[t1.size()-1] ) % mod + mod ) % mod ;
				if( tmp == hs )	ans++ ;
			}
			if( t1[i] != t2[i] )	break ;
		}
		cout << ans << endl ;
	}
	
	q_q ;
}
//	oldmoon:(
//	  |    |---|
//	--|--  |   |
//	  |    |---|
//	|---|  |   |
//	|   |  |---|
//	|---| /    |