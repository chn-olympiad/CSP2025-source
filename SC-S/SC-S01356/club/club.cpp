#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int N = 1e6 + 10 ; 
int n ; 
priority_queue< pair< int , int > > q1 , q2 , q3 ; 

struct node 
{
	int a , b , c ; 
} input[ N ] ; 
int ans = 0 ; 

inline bool cmp1( const node&x , const node &y ) 
{
	return x.a - max( x.b , x.c ) > y.a - max( y.b , y.c ) ;  
}

inline bool cmp2( const node&x , const node &y ) 
{
	return x.b - max( x.a , x.c ) > y.b - max( y.a , y.c ) ;  
}

inline bool cmp3( const node&x , const node &y ) 
{
	return x.c - max( x.b , x.a ) > y.c - max( y.b , y.a ) ;  
}

signed main() 
{
	freopen( "club.in" , "r" , stdin ) ; 
	freopen( "club.out" , "w" , stdout ) ; 
	ios::sync_with_stdio( false ) ;
	cin.tie( 0 ) ; 
	cout.tie( 0 ) ;  
	int T ; 
	cin >> T ; 
	while( T -- ) 
	{
		cin >> n ; 
		for( int i = 1 ; i <= n ; i ++ ) 
			cin >> input[ i ].a >> input[ i ].b >> input[ i ].c ;  
		sort( input + 1 , input + 1 + n , cmp1 ) ;
		ans = 0 ; 
		int now_ans = 0 ;  
		for( int i = 1 ; i <= ( n >> 1 ) ; i ++ ) 
		{
			now_ans += input[ i ].a ; 
		} 
		for( int i = ( n >> 1 ) + 1 ; i <= n ; i ++ ) 
		{
			now_ans += max( input[ i ].b , input[ i ].c ) ; 
		}
		ans = max( ans , now_ans ) ; 
		now_ans = 0 ;  
		sort( input + 1 , input + 1 + n , cmp2 ) ;
		for( int i = 1 ; i <= ( n >> 1 ) ; i ++ ) 
		{
			now_ans += input[ i ].b ; 
		} 
		for( int i = ( n >> 1 ) + 1 ; i <= n ; i ++ ) 
		{
			now_ans += max( input[ i ].a , input[ i ].c ) ; 
		}
		ans = max( ans , now_ans ) ; 
		now_ans = 0 ;  
		sort( input + 1 , input + 1 + n , cmp3 ) ;
		for( int i = 1 ; i <= ( n >> 1 ) ; i ++ ) 
		{
			now_ans += input[ i ].c ; 
		} 
		for( int i = ( n >> 1 ) + 1 ; i <= n ; i ++ ) 
		{
			now_ans += max( input[ i ].a , input[ i ].b ) ; 
		}
		ans = max( ans , now_ans ) ; 
		now_ans = 0 ; 
		for( int i = 1 ; i <= n ; i ++ ) 
		{
			if( input[ i ].a > input[ i ].b && input[ i ].a > input[ i ].c ) 
			{
				pair< int , int > now__ = make_pair( 0 , 0 ) ;
				if( q1.size( ) < ( n >> 1 ) ) 
				{
					q1.push( make_pair( input[ i ].a , i ) ) ; 
					continue ; 
				}
				else 
				{
					if( input[ i ].a > q1.top().first ) 
					{
						now__ = q1.top() ; 
						q1.pop() ; 
						q1.push( make_pair( input[ i ].a , i  ) ) ; 
					}
					else 
					{
						now__ = make_pair( input[ i ].a , i ) ; 
					} 
				}
				if( now__.second )
				{
					if( input[ now__.second ].c > input[ now__.second ].b )
					{
						q3.push( make_pair( input[ now__.second ].c , now__.second ) ) ; 
					}
					else 
					{
						q2.push( make_pair( input[ now__.second ].b , now__.second ) ) ; 
					}
				}
			}
			if( input[ i ].b > input[ i ].a && input[ i ].b > input[ i ].c ) 
			{
				pair< int , int > now__ = make_pair( 0 , 0 ) ;
				if( q2.size( ) < ( n >> 1 ) ) 
				{
					q2.push( make_pair( input[ i ].b , i ) ) ; 
					continue ; 
				}
				else 
				{
					if( input[ i ].b > q2.top().first ) 
					{
						now__ = q2.top() ; 
						q2.pop() ; 
						q2.push( make_pair( input[ i ].b , i  ) ) ; 
					}
					else 
					{
						now__ = make_pair( input[ i ].b , i ) ; 
					} 
				}
				if( now__.second )
				{
					if( input[ now__.second ].a > input[ now__.second ].c )
					{
						q1.push( make_pair( input[ now__.second ].a , now__.second ) ) ; 
					}
					else 
					{
						q3.push( make_pair( input[ now__.second ].c , now__.second ) ) ; 
					}
				}
			}
			if( input[ i ].c > input[ i ].b && input[ i ].c > input[ i ].a ) 
			{
				pair< int , int > now__ = make_pair( 0 , 0 ) ;
				if( q3.size( ) < ( n >> 1 ) ) 
				{
					q3.push( make_pair( input[ i ].c , i ) ) ; 
					continue ; 
				}
				else 
				{
					if( input[ i ].c > q3.top().first ) 
					{
						now__ = q3.top() ; 
						q3.pop() ; 
						q3.push( make_pair( input[ i ].c , i  ) ) ; 
					}
					else 
					{
						now__ = make_pair( input[ i ].c , i ) ; 
					} 
				}
				if( now__.second )
				{
					if( input[ now__.second ].a > input[ now__.second ].b )
					{
						q1.push( make_pair( input[ now__.second ].a , now__.second ) ) ; 
					}
					else 
					{
						q2.push( make_pair( input[ now__.second ].b , now__.second ) ) ; 
					}
				}
			}
		}
		while( !q1.empty() ) now_ans += q1.top().first , q1.pop() ; 
		while( !q2.empty() ) now_ans += q2.top().first , q2.pop() ; 
		while( !q3.empty() ) now_ans += q3.top().first , q3.pop() ; 
		cout << max( ans , now_ans ) << endl ; 
	}
	
	
	
	return 0 ; 
}