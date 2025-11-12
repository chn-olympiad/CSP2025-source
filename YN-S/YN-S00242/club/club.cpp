#include <bits/stdc++.h>
using namespace std ;
#define int long long

struct pf {
	int a1, a2, a3 ;
};

const int N = 1e6 ;
int t, sum = 0 ;
int ans[N] = {} ;

bool cmp1( pf a, pf b ) {
	return a.a1 > b.a1 ;
}

bool cmp2( pf a, pf b ) {
	return a.a2 > b.a2 ;
}

bool cmp3( pf a, pf b ) {
	return a.a3 > b.a3 ;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t ;

	for ( int i = 1 ; i <= t ; i ++ ) {

		int k, a1s = 0, a2s = 0, a3s = 0, a1sum = 0, a2sum = 0, a3sum = 0 ;
		cin >> k ;
		bool vis[N] = {} ;
		pf opp[k] = {} ;

		for ( int j = 0 ; j < k ; j ++ ) {

			cin >> opp[j].a1 >> opp[j].a2 >> opp[j].a3 ;
		}

		sort( opp, opp + k, cmp1 ) ;

		for ( int j = 0 ; j < k ; j ++ ) {

			if ( opp[j].a1 > opp[j].a2 && opp[j].a1 > opp[j].a3 && a1s <= k / 2 && !vis[j] )  {
				a1s ++ ;
				a1sum += opp[j].a1 ;
				vis[j] = true ;
			}
		}

		sort( opp, opp + k, cmp2 ) ;

		for ( int j = 0 ; j < k ; j ++ ) {

			if ( opp[j].a2 > opp[j].a1 && opp[j].a2 > opp[j].a3 && a2s <= k / 2 && !vis[j] )  {
				a2s ++ ;
				a2sum += opp[j].a2 ;
				vis[j] = true ;
			}
		}

		sort( opp, opp + k, cmp3 ) ;

		for ( int j = 0 ; j < k ; j ++ ) {

			if ( opp[j].a3 > opp[j].a2 && opp[j].a3 > opp[j].a1 && a3s <= k / 2 && !vis[j] )  {
				a3s ++ ;
				a3sum += opp[j].a3 ;
				vis[j] = true ;
			}
		}

		ans[i] = a1sum + a2sum + a3sum ;
	}

	for ( int i = 1 ; i <= t ; i ++ ) {

		cout << ans[i] << endl ;
	}

	return 0 ;
}
