#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7 ;
struct Node {
	int fl , el ;
	int sub ;
};
string s1[N] , s2[N] ;
map< Node , int > w ; 
signed main() {
    freopen( "replace.in" , "r" , stdin ) ;
    freopen( "replace.out" , "w" , stdout ) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int n , q ;
    cin >> n >> q ;
    bool u = 1 ;
    int dir1 , dir2 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
    	cin >> s1[i] >> s2[i] ;
	}string t1 , t2 ;
	int cnt = 0 ;
	for ( int i = 1 ; i <= q ; i ++ ) {
		cin >> t1 >> t2 ;
		cnt = 0 ;
		for ( int o = 1 ; o <= n ; o ++ ) {
			string j = s1[o] ;
			for ( int k = 0 ; t1[k] != 0 ; k ++ ) {
				bool u = 1 ;
				for ( int g = k ; g < k + j.size() ; g ++ ) {
					if ( t1[g] != j[ g - k ] ) {
						u = 0 ;
						break ;
					}
				}if ( u == 1 ) {
					string l = t1 ;
					for ( int g = k ; g < k + j.size() ; g ++ ) {
						l[g] = s2[o][ g - k ];
					}if ( l == t2 )	cnt ++ ;
				}
			}
		}
		cout << cnt << "\n" ;
	}
    return 0 ;
}
