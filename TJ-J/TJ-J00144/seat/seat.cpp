#include<bits/stdc++.h>
using namespace std ;
int Mp[12][12] ;
bool vis[12][12] ;
int A[255] ;
int m , n , a ;
int dx[3] = { 1 , 0 , -1 } ;
int dy[3] = { 0 , 1 , 0 } ;

void dfs ( int x , int y , int d ) {
	Mp[x][y] = A[d] ;
	vis[x][y] = 1 ;
	if ( A[d] == a ) {
		cout << y << ' ' << x << endl ;
		return ;
 	}
 	int x1 , y1 ;
 	for ( int i = 0 ; i < 3 ; i++ ) {
 		x1 = x + dx[i] ;
 		y1 = y + dy[i] ;
 		if ( x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && vis[x1][y1] == 0 ) {
			dfs ( x1 , y1 , d - 1 ) ;
			break ;	
		}
	}
}

int main() {
	freopen ( "seat.in" , "r" , stdin ) ;
	freopen ( "seat.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n * m ; i++ ) {
		cin >> A[i] ;
	}
	a = A[1] ;
	sort ( A + 1 , A + ( m * n ) + 1 ) ;
	dfs ( 1 , 1 , m * n ) ;
	return 0 ;
}
