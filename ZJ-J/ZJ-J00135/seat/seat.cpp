#include<bits/stdc++.h>
using namespace std;
int a[ 110 ];
int b[ 20 ][ 20 ];
bool cmp( int a , int b ){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i ++ ){
		cin >> a[ i ];
	}
	int k = a[ 1 ];
	sort( a + 1 , a + n * m + 1 , cmp );
//	for(int i = 1 ; i <= n * m ; i ++ ){
//		cout << a[ i ] << ' ';
//	}
	int t = 1;
	for(int i = 1 ; i <= n / 2 ; i ++ ){
		for( int j = 1 ; j <= m ; j ++ ){
			b[ i * 2 - 1 ][ j ] = a[ t ++ ];
		}
		for( int j = m ; j >= 1 ; j -- ){
			b[ i * 2 ][ j ] = a[ t ++ ];
		}
	}
	if( n % 2 == 1 ){
		for(int j = 1 ; j <= m ; j ++ ){
			b[ n ][ j ] = a[ t ++ ];
		}
	}
	for(int i = 1 ; i <= n ; i ++ ){
		for(int j = 1 ; j <= m ; j ++ ){
			if( b[ i ][ j ] == k ){
				cout << i << ' ' << j ;
				return 0;
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
2 2
98 99 100 97
2 2
99 100 97 98
*/
