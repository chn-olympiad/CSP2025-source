#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

const ll N = 1e2 ;

ll a[N + 5] ;
 
int main()
{
	freopen("seat.in", "r", stdin) ;
	freopen("seat.out", "w", stdout) ;
	
	ll n, m ;
	cin >> n >> m ;
	
	for(ll i = 1 ; i <= n * m ; i ++)
	{
		cin >> a[i] ;
	}
	
	ll x = a[1] ;
	
	sort(a + 1, a + 1 + n * m) ;
	
	for(ll i = 1 ; i <= n * m ; i ++)
	{
		ll pos = n * m - i + 1 ;
		
		if(a[pos] == x)
		{
			ll hang = (i - 1) / n + 1 ;
			ll lie = (i - 1) % n + 1 ;
			
			if(hang % 2 == 0)
			{
				lie = m - lie + 1 ;
			}
			
			cout << hang << ' ' << lie << '\n' ;
		}
	}
	
	return 0 ;
}
