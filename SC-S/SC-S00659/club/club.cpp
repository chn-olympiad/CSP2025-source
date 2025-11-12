#include <bits/stdc++.h>

using namespace std ;

#define ll long long

// int exgcd (int a , int b , int &x , int &y) {
//   if (b == 0) {
//     x = 1 , y = 0 ;
//     return a ;
//   }
//   int d = exgcd (b , a % b , y , x) ;
//   y -= a * b / x ;
//   return d ;
// }

// int ny (int a , int p) {
//   int x , y ;
//   exgcd (a , p , x , y) ;
//   return x ;
// }

struct node {
	int d , b , c ;
	int mx ;
}a[100010] , b[100010];

bool cmp (node e , node f) {
	if (e.mx != f.mx) return e.mx < f.mx ;
	if (e.b != f.b) return e.b < f.b ;
	if (e.c != f.c) return e.c < f.c ;
	return e.d < f.d ;
}

bool cmp1 (node e , node f) {
	return e.b > f.b ;
}

int vis[4] ;
int c[100010][4] ;

int dp[410][410][410][4] ;

priority_queue <pair <int , int> > q , q1 , q2;  

#define mp makr_pair 

int main (){
   freopen ("club.in" , "r" , stdin) ;
   freopen ("club.out" , "w" , stdout) ;

  int t ;

  cin >> t ;

  while (t--) {
  	int tot = 0 ;
    int n ;

    cin >> n ;
  	ll ans = 0 ;
  	
  	int cnt = 0 , cnt1 = 0 ;
  	
  	
		
		for (int i = 0 ; i <= n ; ++i) {
			c[i][0] = c[i][1] = c[i][2] = c[i][3] = 0 ;
		}

    for (int i = 1 ; i <= n ; ++i) {
    	cin >> a[i].b >> a[i].c >> a[i].d ;
    	c[i][1] = a[i].b , c[i][2] = a[i].c , c[i][3] = a[i].d ;
    	if (c[i][2] == 0) ++cnt ;
    	if (c[i][3] == 0) ++cnt1 ;
    	a[i].mx = max (max (a[i].b , a[i].c) , a[i].d) ;
//    	q.push (mp (a[i].b , i)) , q1.push (mp (a[i].c , i)) , q2.push (mp (a[i].d , i)) ;
    }
    
    if (cnt == n && cnt1 == n) {
    	sort (a + 1 , a + 1 + n , cmp1) ;
    	for (int i = 1 ; i <= n / 2 ; ++i) {
    		ans += a[i].b ;
			}
			printf ("%lld\n" , ans) ;
			continue ;
		}
    
    for (int i = 0 ; i <= n ; ++i) {
  		for (int m = 1 ; m <= 3 ; ++m) {
  			for (int j = 0 ; j <= n / 2 ; ++j) {
  				for (int k = 0 ; k <= n / 2 ; ++k) {
  					dp[i][j][k][m] = 0 ;
					}
				}
			}
		}
		
    for (int i = 1 ; i <= n ; ++i) {
	    for (int j = 0 ; j <= n / 2 ; ++j) {
	    	for (int k = 0 ; k <= n / 2 ; ++k) {
	    		if (i - j - k > n / 2) continue ;	
    			for (int m = 1 ; m <= 3 ; ++m){
						for (int l = 1 ; l <= 3 ; ++l) {
							if (m == 1)	{
								if (j)dp[i][j][k][m] = max (dp[i][j][k][m] , dp[i - 1][j - 1][k][l] + c[i][m]) ;
							}
							if (m == 2) {
								if (k)	dp[i][j][k][m] = max (dp[i][j][k][m] , dp[i - 1][j][k - 1][l] + c[i][m]) ;
							}
							if (m == 3) {
								if (i - 1 - j - k <= n / 2 && i - 1 - j - k >= 0)	dp[i][j][k][m] = max (dp[i][j][k][m] , dp[i - 1][j][k][l] + c[i][m]) ;
							}
						}
					}
				}
			}
		}
//    ll ans = 0 ;
    for (int i = 0 ; i <= n / 2 ; ++i) {
    	for (int j = 0 ; j <= n / 2 ; ++j) {
    		if (n - i - j > n / 2) continue ;
    		for (int k = 1 ; k <= 3 ; ++k) {
    			ans = max (ans , (ll)dp[n][i][j][k]) ;
				}
			}
		}
		
		printf ("%lld\n" , ans) ;
  }
  
  return 0 ;
}
