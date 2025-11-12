#include<bits/stdc++.h>
using namespace std ;

int a1 [ 1000 ] [ 1000 ] ;
int a2 [ 1000 ] [ 1000 ] ;
int a3 [ 1000 ] [ 1000 ] ;

int main ( ){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t ;
	int n ;
	int cnt = 0 ;
	double ans = n / 2 ;
	
	cin >> t >> n ;
	
	for ( int i = 0 ; i < t ;  i ++ ){
		
		for ( int j = 0 ; j < n ; j ++ ){
			
			cin >> a1 [ i ] [ j ] ;
			cin >> a2 [ i ] [ j ] ; 
			cin >> a3 [ i ] [ j ] ;
			
		}
		
	}
	
	for ( int i = 1 ; i <= t ; i ++ ){
		for ( int j = 1 ; j <= n ; j ++ ){
			
			if ( a1[ i ][ j ] !=0 ){
				
				ans ++ ;
				
			}
		}
	}
	
	cout << ans ;
	
}
