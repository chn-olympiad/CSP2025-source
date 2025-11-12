#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 1e5 + 5 ;
int T , n , ans , fl1 , fl2 , fl3 ;
struct node {
	int a , b , c , id1 , id2 , id3 ;
} a [N] ;
bool cmp1 (node q , node h) {
	if (q.id1 == 1 && h.id1 != 1)  return 1 ;
	if (q.id1 != 1 && h.id1 == 1)  return 0 ;
	int x = 0 , xx = 0 , y = 0 , yy = 0 ;
	if (q.id2 == 2)  x = q.b , xx = q.c ;
	else  x = q.c , xx = q.b ;
	if (h.id2 == 2)  y = h.b , yy = h.c ;
	else  y = h.c , yy = h.b ;
	if (q.a - x != h.a - y)   return q.a - x < h.a - y ;
	else  return q.a - xx < h.a - yy ; 
}

bool cmp2 (node q , node h) {
	if (q.id1 == 2 && h.id1 != 2)  return 1 ;
	if (q.id1 != 2 && h.id1 == 2)  return 0 ;
	int x = 0 , xx = 0 , y = 0 , yy = 0 ;
	if (q.id2 == 1)  x = q.a , xx = q.c ;
	else  x = q.c , xx = q.a ;
	if (h.id2 == 1)  y = h.a , yy = h.c ;
	else  y = h.c , yy = h.a ;
	if (q.b - x != h.b - y)   return q.b - x < h.b - y ;
	else  return q.b - xx < h.b - yy ; 
}

bool cmp3 (node q , node h) {
	if (q.id1 == 3 && h.id1 != 3)  return 1 ;
	if (q.id1 != 3 && h.id1 == 3)  return 0 ;
	int x = 0 , xx = 0 , y = 0 , yy = 0 ;
	if (q.id2 == 1)  x = q.a , xx = q.b ;
	else  x = q.b , xx = q.a ;
	if (h.id2 == 1)  y = h.a , yy = h.b ;
	else  y = h.b , yy = h.a ;
	if (q.c - x != h.c - y)   return q.c - x < h.c - y ;
	else  return q.c - xx < h.c - yy ; 
}
signed main () {
	freopen ("club.in" , "r" , stdin) ;
	freopen ("club.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (NULL) ; cout.tie (NULL) ;
	cin >> T ;
	while (T --) {
		cin >> n ; ans = 0 ; fl1 = fl2 = fl3 = 0 ;
		for (int i = 1 ; i <= n ; i ++) {
			cin >> a [i].a >> a [i].b >> a [i].c ;
			if (a [i].a >= max (a [i].b , a [i].c)) {
				a [i].id1 = 1 ; fl1 ++ ;  
				ans += a [i].a ;
				if (a [i].b >= a [i].c) {
					a [i].id2 = 2 ;
					a [i].id3 = 3 ;
				}
				else {
					a [i].id2 = 3 ;
					a [i].id3 = 2 ;
				}
			}
			else if (a [i].b >= max (a [i].a , a [i].c)) {
				a [i].id1 = 2 ; fl2 ++ ;
				ans += a [i].b ;
				if (a [i].a >= a [i].c) {
					a [i].id2 = 1 ;
					a [i].id3 = 3 ;
				}
				else {
					a [i].id2 = 3 ;
					a [i].id3 = 1 ;
				}
			}
			else {
				a [i].id1 = 3 ; fl3 ++ ;
				ans += a [i].c ;
				if (a [i].a >= a [i].b) {
					a [i].id2 = 1 ;
					a [i].id3 = 2 ;
				}
				else {
					a [i].id2 = 2 ;
					a [i].id3 = 1 ;
				}
			}
		}
		if (fl1 > n / 2) {
			sort (a + 1 , a + 1 + n , cmp1) ;
			for (int i = 1 ; fl1 > n / 2 ; i ++ ) {
				int x = a [i].id2 ;
				if (x == 2) {
					if (fl2 > n / 2) {
						ans -= a [i].a ;
						ans += a [i].c ; 
						fl1 -- ; fl3 ++ ;
					}
					else {
						ans -= a [i].a ;
						ans += a [i].b ;
						fl1 -- ; fl2 ++ ;
					}
				}
				else {
					if (fl3 > n / 2) {
						ans -= a [i].a ;
						ans += a [i].b ; 
						fl1 -- ; fl2 ++ ;
					}
					else {
						ans -= a [i].a ;
						ans += a [i].c ;
						fl1 -- ; fl3 ++ ;
					}
				}
			}
		}
		else if (fl2 > n / 2) {
			sort (a + 1 , a + 1 + n , cmp2) ;
			for (int i = 1 ; fl2 > n / 2 ; i ++) {
				int x = a [i].id2 ;
				if (x == 1) {
					if (fl1 > n / 2) {
						ans -= a [i].b ;
						ans += a [i].c ; 
						fl2 -- ; fl3 ++ ;
					}
					else {
						ans -= a [i].b ;
						ans += a [i].a ;
						fl2 -- ; fl1 ++ ;
					}
				}
				else {
					if (fl3 > n / 2) {
						ans -= a [i].b ;
						ans += a [i].a ; 
						fl2 -- ; fl1 ++ ;
					}
					else {
						ans -= a [i].b ;
						ans += a [i].c ;
						fl2 -- ; fl3 ++ ;
					}
				}
			}
		}
		else if (fl3 > n / 2) {
			sort (a + 1 , a + 1 + n , cmp3) ;
			for (int i = 1 ; fl3 > n / 2 ; i ++) {
				int x = a [i].id2 ;
				if (x == 1) {
					if (fl1 > n / 2) {
						ans -= a [i].c ;
						ans += a [i].b ; 
						fl3 -- ; fl2 ++ ;
					}
					else {
						ans -= a [i].c ;
						ans += a [i].a ;
						fl3 -- ; fl1 ++ ;
					}
				}
				else {
					if (fl2 > n / 2) {
						ans -= a [i].c ;
						ans += a [i].a ; 
						fl3 -- ; fl1 ++ ;
					}
					else {
						ans -= a [i].c ;
						ans += a [i].b ;
						fl3 -- ; fl2 ++ ;
					}
				}
			}
		}
		cout << ans << "\n" ;
	}
	return 0 ;
}
/*
miaomiao AC
by 927003
终于100pts了，17:39 ，逆天改命 
*/
