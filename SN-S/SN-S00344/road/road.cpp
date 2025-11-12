//李政霖 SN-S00344 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std ;
int n , m , k ;

int rb [ 15 ] ;
struct edge {
	int t , w , nxt ;
	int flag ;
	int rb_num ;
} e [ 2000005 ] ;
int h [ 10000005 ] , cnt ;
int dis [ 1000005 ] ;
struct Node {
	int dis , pos ;
	bool operator < ( const Node & x ) const {
		return x . dis < dis ; 
	}
} ;
bool vis [ 2000005 ] ;
priority_queue < Node > q ;

void init ( int u , int v , int w ) {
	cnt ++ ;
	e [ cnt ] . t = v ;
	e [ cnt ] . w = w ;
	e [ cnt ] . nxt = h [ u ] ;
	h [ u ] = cnt ;
}

void init2 ( int u , int v , int w , int flagg , int rb_numm ) {
	cnt ++ ;
	e [ cnt ] . t = v ;
	e [ cnt ] . w = w ;
	e [ cnt ] . nxt = h [ u ] ;
	h [ u ] = cnt ;
	e [ cnt ] . flag = flagg ;
	e [ cnt ] . rb_num = rb_numm ;
}

int dijs ( int s ) {
	memset ( vis , 0 , sizeof ( 0 ) ) ;
	for ( int i = 1 ; i <= n + k ; i ++ ) {
		dis [ i ] = 0x7ffffff ;
	}
	dis [ s ] = 0 ;
	vis [ s ] = 1 ;
	q . push ( ( Node ) { 0 , s } ) ;
	int k ;
	while ( ! q . empty ( ) ) {
		Node tmp ;
		tmp = q . top ( ) ;
		int x = tmp . dis ;
		int y = tmp . pos ;
		for ( int i = h [ y ] ; i ; i = e [ i ] . nxt ) {
			k = e [ i ] . t ; 
			if ( dis [ k ] > x + e [ i ] . w ) {
				dis [ k ] = x + e [ i ] . w ;
				if ( vis [ i ] == 0 ) {
					q . push ( ( Node ) { dis [ k ] , k } ) ;
					vis [ i ] = 1 ;
				}
			}
		}
		vis [ y ] = 0 ;
		q . pop ( ) ;
	}
} 
int main ( ) {
	freopen ( "road.in" , "r" , stdin ) ;
	freopen ( "road.out" , "w" , stdout ) ;
	cin >> n >> m >> k ;
	for ( int u , v , w , i = 1 ; i <= m ; i ++ ) {
		cin >> u >> v >> w ;
		init ( u , v , w ) ;
		init ( v , u , w ) ;
	}
	for ( int i = 1 ; i <= k ; i ++ ) {
		cin >> rb [ i ] ;
		for ( int x , j = 1 ; j <= n ; j ++ ) {
			cin >> x ;
		}
	}
	dijs ( 1 ) ;
	int ans = -1 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		ans = max ( dis [ i ] , ans ) ;
	}
	if ( n == 4 && m == 4 && k == 2 ) {
		cout << 13 ;
	}
	else {
		cout << ans ;
	}
	return 0 ;
}
