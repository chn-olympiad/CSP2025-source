#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

const ll N = 1e5 ;

struct Node
{
	ll x, y, z ;
} ;

Node a[N + 5] ;

ll s[N + 5] ;

int main()
{
	freopen("club.in", "r", stdin) ;
	freopen("club.out", "w", stdout) ;
	
	ll T ;
	cin >> T ;
	
	while(T --)
	{
		ll n ;
		cin >> n ;
		
		ll m = n / 2 ;
		
		for(ll i = 1 ; i <= n ; i ++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z ;
		}
		
		ll xcnt = 0, ycnt = 0, zcnt = 0 ;
		
		ll ans = 0 ;
		
		for(ll i = 1 ; i <= n ; i ++)
		{
			ll num = max(a[i].x, max(a[i].y, a[i].z)) ;
			ans += num ;
			
			if(num == a[i].x) xcnt ++ ;
			if(num == a[i].y) ycnt ++ ;
			if(num == a[i].z) zcnt ++ ;
		}
		
		if(xcnt > m)
		{
			for(ll i = 1 ; i <= n ; i ++)
			{
				ll x = min(a[i].x - a[i].y, a[i].x - a[i].z) ;
				s[i] = x > 0 ? x : INT_MAX ;
			}
			
			sort(s + 1, s + 1 + n) ;
			
			for(ll i = 1 ; i <= xcnt - m ; i ++)
			{
				ans -= s[i] ;
			}
		}
		
		if(ycnt > m)
		{
			for(ll i = 1 ; i <= n ; i ++)
			{
				ll x = min(a[i].y - a[i].x, a[i].y - a[i].z) ;
				s[i] = x > 0 ? x : INT_MAX ;
			}
			
			sort(s + 1, s + 1 + n) ;
			
			for(ll i = 1 ; i <= ycnt - m ; i ++)
			{
				ans -= s[i] ;
			}
		}
		
		if(zcnt > m)
		{
			for(ll i = 1 ; i <= n ; i ++)
			{
				ll x = min(a[i].z - a[i].x, a[i].z - a[i].y) ;
				s[i] = x > 0 ? x : INT_MAX ;
			}
			
			sort(s + 1, s + 1 + n) ;
			
			for(ll i = 1 ; i <= zcnt - m ; i ++)
			{
				ans -= s[i] ;
			}
		}
		
		cout << ans << '\n' ;
	}
	
	return 0 ;
}
