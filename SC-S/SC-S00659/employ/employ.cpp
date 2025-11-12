#include <bits/stdc++.h>

using namespace std ;

#define ll long long

int n , m ;
char s[510] ;

const int mod = 998244353 ; 

int c[510] ;

int p[510] ;
bool vis[510] ;
ll ans = 0 ;

void dfs (int x) {
	if (x > n) {
		int cnt = 0 ;
		int res = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
//			if (p[1] == 1 && p[2] == 3 && p[3] == 2) {
//				cerr << "::" << s[i] << " " << cnt << " " << c[p[i]] << '\n' ;
//			}
			if (s[i] == '0' || cnt >= c[p[i]]) {
				++cnt ;
				continue ; 
			}
			++res ;
		}
		if (res >= m) {
			ans = (ans + 1) % mod ;
//			for (int i = 1 ; i <= n ; ++i) {
//				printf ("%lld " , p[i]) ;
//			}
//			puts("") ;
		}
		return ;
	}
	for (int i = 1 ; i <= n ; ++i) {
		if (!vis[i]) {
			p[x] = i ;
			vis[i] = 1 ;
			dfs (x + 1) ;
			vis[i] = 0 ;
		}
	}
}

ll mul (ll a , ll b) {
	ll res = 0 ;
	for (int i = 1 ; i <= b ; ++i) {
		res = (res + a) % mod ;
	}
	return res ;
}

int main (){
   freopen ("employ.in" , "r" , stdin) ;
   freopen ("employ.out" , "w" , stdout) ;
  
  cin >> n >> m ;
  
  for (int i = 1 ; i <= n ; ++i) {
  	cin >> s[i] ;
	}
  
  int rp = 0 ;
  
  for (int i = 1 ; i <= n ; ++i) {
  	if (s[i] == '1') ++rp ;
	}
  
  for (int i = 1 ; i <= n ; ++i) {
  	cin >> c[i] ;
	}
	printf ("%lld\n" , rp) ;
	if (rp == n) {
		ans = 1 ;
		for (int i = 1 ; i <= n ; ++i) {
			ans = mul (ans , i) % mod ;
		}
		printf ("%lld\n" , ans) ;
		return 0 ;
	}
	
	dfs (1) ;
	
	printf ("%lld\n" , ans) ;
  
  return 0 ;
}
