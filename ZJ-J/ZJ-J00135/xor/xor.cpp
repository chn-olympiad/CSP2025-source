#include<bits/stdc++.h>
using namespace std;
int a[ 500010 ][ 30 ];
int p[ 30 ];
bool b[ 1010 ][ 1010 ];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n , k;
	cin >> n >> k;
	int t = 0;
	while( k != 0 ) {
		p[ t ++ ] = k % 2 ;
		k /= 2;
	}
	for(int i = 1 ; i <= n ; i ++ ){
		t = 0;
		int x;
		cin >> x;
		while( x != 0 ){
			a[ i ][ t ++ ] = x % 2;
			x /= 2;
		}
	}
	for(int k = 0 ; k <= 19 ; k ++ ){
		for(int i = 1 ; i <= n ; i ++ ){
			bool f = 0;
			for(int j = i ; j <= n ; j ++ ){
				f = f ^ a[ j ][ k ];
				if( f != p[ k ] ) b[ i ][ j ] = 1;
			}
		}
	}
	int tot = 0;
	for(int i = 1 ; i <= n ; i ++ ){
		for(int j = i ; j <= n ; j ++ ){
			if( !b[ i ][ j ] ){
				tot ++;
				i = j + 1;
			}
		}
	}
	cout << tot;
	return 0;
}
