#include <bits/stdc++.h>
using namespace std;
int t,n;
#define ll long long
ll a[100000 + 5][4];
ll p[100000 + 5][4];
ll d[100000 + 5];
int cnt[4];
int main () {
	freopen ("club.in" , "r" , stdin) ;
	freopen ("club.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1;i <= n;i ++) 
			cin >> a[i][1] >> a[i][2] >> a[i][3] ;
		ll ans = 0;
		cnt[1] = 0,cnt[2] = 0,cnt[3] = 0;
		for (int i = 1;i <= n;i ++) {
			ll x = max (max (a[i][1] , a[i][2]) , a[i][3]) ;
			ans += x;
			if (x == a[i][1]) p[++ cnt[1]][1] = i;
			else if (x == a[i][2]) p[++ cnt[2]][2] = i;
			else p[++ cnt[3]][3] = i;
		}
		bool flag = false ;
		int id = 0;
		if (cnt[1] > n/2) 
			id = 1;
		else if (cnt[2] > n/2) 
			id = 2;
		else if (cnt[3] > n/2)
			id = 3;
		else {
			flag = true;
		}
		if (!flag) {
			for (int i = 1;i <= cnt[id];i ++) {
				d[i] = -(1LL << 30);
				for (int j = 1;j <= 3;j ++) {
					if (j != id) {
						d[i] = max (d[i] , a[p[i][id]][j] - a[p[i][id]][id]) ;
					}
				}
			}
			sort (d + 1,d + cnt[id] + 1) ;
			for (int i = cnt[id] ; i > n / 2;i --) {
				ans += d[i] ;
			}
		}
		cout << ans << "\n" ;
	}
	return 0;
}