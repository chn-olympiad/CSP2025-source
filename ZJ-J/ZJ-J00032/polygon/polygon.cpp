#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

const ll N = 5e3 ;

const ll M = 2e7 ;

const ll Mod = 998244353 ;

ll a[N + 5] ;

ll S[N + 5] ;

ll F[M + 5] ;

ll G[2][M + 5] ;

ll K[N + 5] ;

int main()
{
	freopen("polygon.in", "r", stdin) ;
	freopen("polygon.out", "w", stdout) ;
	
	ll n, sum = 0 ;
	cin >> n ;
	
	for(ll i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ;
		S[i] = S[i - 1] + a[i] ;
	}
	
	sort(a + 1, a + 1 + n) ;
	
	F[0] = 1 ;
	
	for(ll i = 1 ; i <= n ; i ++)
	{
		for(ll j = 1 ; j <= S[i] ; j ++)
		{
			F[j] = 0 ;
			F[j] += G[i % 2][j] ;
			F[j] %= Mod ;
			
			G[(i + 1) % 2][j] = G[i % 2][j] ;
			
			if(j - a[i] >= 0)
			{
				G[(i + 1) % 2][j] += F[j - a[i]] ;
			}
			
			G[i % 2][j] %= Mod ;
			
			if(j >= a[i] + 1)
			{
				K[i] += F[j] ;
			}
		}
	}
	
//	for(int i = 1 ; i <= n ; i ++)
//	{
//		for(int j = 0 ; j <= 15 ; j ++)
//		{
//			cout << F[i][j] << ' ' ;
//		}
//		
//		cout << '\n' ;
//	}
	
	ll ans = 0 ;
	
	for(ll i = 1 ; i <= n ; i ++)
	{
		ans += K[i] ;
		ans %= Mod ;
	}
	
	cout << ans << '\n' ;
	
	return 0 ;
}
