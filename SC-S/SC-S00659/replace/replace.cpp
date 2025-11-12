#include <bits/stdc++.h>

using namespace std ;

#define ll long long

int n , q ;

string s[200010][3] ;

map <string , int> mp ;

int main (){
   freopen ("replace.in" , "r" , stdin) ;
   freopen ("replace.out" , "w" , stdout) ;
  
  cin >> n >> q ;
  
  for (int i = 1 ; i <= n ; ++i) {
  	cin >> s[i][0] >> s[i][1] ;
	}
	
	
	while (q--) {
		string t , tt ;
		cin >> t >> tt ;
		int m = t.size() , mm = tt.size() ;
		t = ' ' + t , tt = tt ;
		ll ans = 0 ;
		for (int i = 1 ; i <= m ; ++i) {
			string tmp = "" ; 
			for (int j = i ; j <= m ; ++j) {
				tmp += t[j] ;
				int rs = 0 ;
				for (int k = 1 ; k <= n ; ++k) {
					if (s[i][0] == tmp) ++rs; 
				}
				if (rs == 0) continue ;
				string tmp1 = "" , tmp2 = "" ;
				for (int k = 1 ; k < i ; ++k) {
					tmp1 += t[k] ;
				}
				for (int k = j + 1 ; k <= m ; ++k) {
					tmp2 += t[k] ;
				}
				for (int k = 1 ; k <= n ; ++k) {
					if (tmp == s[k][0]) {
						string ss = tmp1 + s[k][1] + tmp2 ;
//						cerr << tmp1 << " " << s[i][1] << " " << tmp2 << "::\n" ;
						if (ss == tt) {
							++ans ;
							
						}
					}
				}
			}
		}
		printf ("%lld\n" , ans) ;
	}
  
  return 0 ;
}
