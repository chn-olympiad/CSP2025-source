#include<bits/stdc++.h>
using namespace std;
struct ddd{
	int a1,a2,a3,b1,b2,b3;
}pp[ 100010 ];
bool cmp1( ddd a , ddd b ){
	return a.b1 > b.b1;
}
bool cmp2( ddd a , ddd b ){
	return a.b2 > b.b2;
}
bool cmp3( ddd a , ddd b ){
	return a.b3 > b.b3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while( T -- ){
		int n;
		cin >> n;
		for(int i = 1 ; i <= n ; i ++ ){
			cin >> pp[ i ].a1 >> pp[ i ].a2 >> pp[ i ].a3;
		}
		int mat1 = 0;
		int mat2 = 0;
		int mat3 = 0;
		for(int i = 1 ; i <= n ; i ++ ){
			pp[ i ].b1 = pp[ i ].a1 - max( pp[ i ].a2 , pp[ i ].a3 );
			pp[ i ].b2 = pp[ i ].a2 - max( pp[ i ].a1 , pp[ i ].a3 );
			pp[ i ].b3 = pp[ i ].a3 - max( pp[ i ].a1 , pp[ i ].a2 );
			if( pp[ i ].b1 > 0 ) mat1 ++;
			if( pp[ i ].b2 > 0 ) mat2 ++;
			if( pp[ i ].b3 > 0 ) mat3 ++;
		}
//		cout << mat1 << ' ' << mat2 << ' ' << mat3 << '\n';
		long long tot = 0;
		if( mat1 > n / 2 ){
			sort( pp + 1 , pp + n + 1 , cmp1 );
			for(int i = 1 ; i <= n / 2 ; i ++ ){
				tot += pp[ i ].a1;
			}
			for(int i = n / 2 + 1 ; i <= n ; i ++ ){
				tot += max( pp[ i ].a2 , pp[ i ].a3 );
			}
		}else if( mat2 > n / 2 ){
			sort( pp + 1 , pp + n + 1 , cmp2 );
			for(int i = 1 ; i <= n / 2 ; i ++ ){
				tot += pp[ i ].a2;
			}
			for(int i = n / 2 + 1 ; i <= n ; i ++ ){
				tot += max( pp[ i ].a1 , pp[ i ].a3 );
			}
		}else if( mat3 > n / 2 ){
			sort( pp + 1 , pp + n + 1 , cmp3 );
			for(int i = 1 ; i <= n / 2 ; i ++ ){
				tot += pp[ i ].a3;
			}
			for(int i = n / 2 + 1 ; i <= n ; i ++ ){
				tot += max( pp[ i ].a2 , pp[ i ].a1 );
			}
		}else {
			for(int i = 1 ; i <= n ; i ++ ){
				tot += max( max( pp[ i ].a1 , pp[ i ].a2 ) , pp[ i ].a3 );
			}
		}
		
//		for(int i = 1 ; i <= n ; i ++ ){
//			cout << pp[ i ].a1 << ' ' << pp[ i ].a2 << ' ' << pp[ i ].a3 << ' ' << pp[ i ].b1 << ' ' << pp[ i ].b2 << ' ' << pp[ i ].b3 << '\n';
//		}
		cout << tot << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
