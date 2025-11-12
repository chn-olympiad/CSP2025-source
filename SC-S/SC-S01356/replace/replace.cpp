#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int N = 1e6 + 30 ; 
int n , m , k ; 
struct node 
{
	int left ; 
	int right ; 
	int weight ; 
	bool operator < ( const node &a ) const 
	{
		return weight < a.weight ; 
	}
}edge[ N ] ; 
int fa[ N ] ; 
int mape[ 13 ][ N >> 2 ] ;  
int belong[ 40 ] ; 
int optre[ 40 ] ; 
int find( int x ) 
{
	if( fa[ x ] == x ) return x ; 
	return fa[ x ] = find( fa[ x ] ) ; 
}

pair< int , int > find__ans( int fx , int fy ) 
{
	int ans = LLONG_MAX ;
	int lo = 0 ; 
	int flage = -1 ; 
	for( int i = 1 ; i <= k ; i ++ ) 
	{
		if( fa[ i + n ] != 0 ) 
		{
			int fz = find( i + n ) ; 
			if( fz != fx && fz != fy ) 
			{
				if( mape[ i ][ fx ] + mape[ i ][ fy ] < ans || ( mape[ i ][ fx ] + mape[ i ][ fy ] == ans && flage < 2 )) 
				{
					ans = mape[ i ][ fx ] + mape[ i ][ fy ] ; 
					flage = 2 ; 
					lo = i ; 
				}
			}
			else if( fx == fz || fy == fz ) 
			{
				if( ( fx == fz ? 0 : mape[ i ][ fx ] ) + ( fy == fz ? 0 : mape[ i ][ fy ] ) < ans || ( ( fx == fz ? 0 : mape[ i ][ fx ] ) + ( fy == fz ? 0 : mape[ i ][ fy ] ) == ans && flage < 3 ) ) 
				{
					ans = ( fx == fz ? 0 : mape[ i ][ fx ] ) + ( fy == fz ? 0 : mape[ i ][ fy ] ) ; 
					lo = i ; 
					flage = 3 ; 
				}
			}
		}
		else
		{
			int a = mape[ i ][ fx ] + mape[ i ][ fy ] + optre[ i ] ; 
			if( a < ans || ( a == ans && flage < 1 ) ) 
			{
				ans = a ;  
				lo = i ; 
				flage = 1 ; 
			}
		}
	} 
	return make_pair( ans , lo ) ; 
}

signed main () 
{
	freopen( "road.in" , "r" , stdin ) ; 
	freopen( "replace.out" , "w" , stdout ) ; 
	ios::sync_with_stdio( false ) ; 
	cin.tie( 0 ) , cout.tie( 0 ) ; 
	cin >> n >> m >> k ; 
	for( int i = 1 ; i <= m ; i ++ ) 
		cin >> edge[ i ].left >> edge[ i ].right >> edge[ i ].weight ;
	sort( edge + 1 , edge + 1 + m ) ; 
	for( int i = 1 ; i <= k ; i ++ ) 
	{
		cin >> optre[ i ] ; 
		for( int j = 1 ; j <= n ; j ++ ) cin >> mape[ i ][ j ] ; 
	}
	
	for( int i = 1 ; i <= n ; i ++ ) fa[ i ] = i ; 
	int ans = 0 ; 
	for( int i = 1 ; i <= m ; i ++ ) 
	{
		int fx = find( edge[ i ].left ) , fy = find( edge[ i ].right ) ; 
		if( fx == fy ) continue ; 
		pair< int , int > id = find__ans( fx , fy ) ; 
		if( id.first <= edge[ i ].weight ) 
		{
			if( fa[ id.second + n ] == 0 )
				fa[ id.second + n ] = fx ; 
			else if( fa[ id.second + n ] != fx && fa[ id.second + n ] != fy ) 
			{
				int fz = find( id.second + n ) ; 
				fa[ fz ] = fx ; 
				for( int j = 1 ; j <= k ; j ++ )
				{
					mape[ j ][ fx ] = min( mape[ j ][ fx ] , mape[ j ][ fz ] ) ; 
				}
				
			}
			ans += id.first ; 
			fa[ fy ] = fx ; 
		}
		else 
		{
			fa[ fy ] = fx ; 
			ans += edge[ i ].weight ;
		}
		for( int j = 1 ; j <= k ; j ++ )
		{
			mape[ j ][ fx ] = min( mape[ j ][ fx ] , mape[ j ][ fy ] ) ; 
		}
	}
	cout << ans << "\n" ; 
	return 0 ; 
}