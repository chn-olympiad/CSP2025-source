#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

const ll N = 5e5 ;

const ll M = 1048576 ;

ll a[N + 5], xr[N + 5] ;

vector<ll> s[M + 5] ;

ll pos[M + 5] ;

int main()
{
	freopen("xor.in", "r", stdin) ;
	freopen("xor.out", "w", stdout) ;

	ll n, k ;
	cin >> n >> k ;
	
	for(ll i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ;
	}
	
	for(ll i = 1 ; i <= n ; i ++)
	{
		xr[i] = xr[i - 1] ^ a[i] ;
//		cout << xr[i - 1] << ' ' << a[i] << ' ' << xr[i] << '\n' ;
	}
	
	for(ll i = 1 ; i <= n ; i ++)
	{
		s[xr[i]].push_back(i) ;
	}
	
	ll r = 0, lstx = 0 ;
	ll ans = 0 ;
	
	for(ll i = 1 ; i <= n ; i ++)
	{
		ll x = xr[i - 1] ^ k ;
		
		while(pos[x] < s[x].size() && s[x][pos[x]] < i)
		{
			pos[x] ++ ;
		}
		
		if(pos[x] >= s[x].size())
		{
			continue ;
		}
		
		ll t = s[x][pos[x]] ;
		
//		cout << i << ' ' << x << ' ' << t << '\n' ; 
		
		if(i <= r)
		{
			if(t > r)
			{
				continue ;
			}
			
			pos[lstx] -- ;
			
			r = t ;
			pos[x] ++ ;
			lstx = x ;
		} 
		else
		{
			r = t ;
			pos[x] ++ ;
			
			lstx = x ;
			ans ++ ;
		}
		
//		cout << r << ' ' << ans << '\n' ;
	}
	
	cout << ans << '\n' ;
	
	return 0 ;
}

