#include<bits/stdc++.h> 
using namespace std ;
const int N=600+5 , Mod = 1e9 + 10 ;
int n , m ;
int fav[ N ][ 4 ] ;
#define ll longlong
#define igate( a , b ) for( int i = (a) ; i <= (b) ; i++ )
#define jgate( a , b ) for( int j = (a) ; j <= (b) ; j++ )
#define kgate( a , b ) for( int k = (a) ; k <= (b) ; k++ )
typedef pair< int , int > P ;
int ans = 0 ;
int f[ N ][ N ][ N ] ;

int main(){
	freopen( "club.in" , "r" , stdin ) ;
	freopen( "club.out" , "w" , stdout ) ;
	int t ; 
	cin >> t ;
	kgate( 1 , t ){
		ans = 0 ;
		memset( f , -0x3f , sizeof f ) ;
		cin >> n ;
		
		igate( 1 , n )jgate( 1 , 3 ) cin >> fav[ i ][ j ] ;
		f[ 1 ][ 1 ][ 0 ] = fav[ 1 ][ 1 ] ;
		f[ 1 ][ 0 ][ 1 ] = fav[ 1 ][ 2 ] ;
		f[ 1 ][ 0 ][ 0 ] = fav[ 1 ][ 3 ] ;
		
		for( int x = 2 ; x <= n ; x++ )igate( 0 , min( x , n / 2 ) )jgate( 0 , min( x - i , n / 2 ) ){
			int u = x - i - j ;if( u > n / 2 ) continue ;
			
			f[ x ][ i ][ j ] = max( f[ x - 1 ][ i - 1 ][ j ] + fav[ x ][ 1 ] , max( f[ x - 1 ][ i ][ j - 1 ] + fav[ x ][ 2 ] , 
					f[ x - 1 ][ i ][ j ] + fav[ x ][ 3 ] ) ) ;
			
			if( x == n ) ans = max( ans , f[ x ][ i ][ j ] ) ;
		}
		
		cout << ans << endl ;
	}
}

