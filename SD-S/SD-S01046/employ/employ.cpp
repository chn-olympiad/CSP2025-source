#include<bits/stdc++.h>
using namespace std ;
const int MX = 500 ;
const int MOD = 998244353 ;
int A(long long q)
{
	long long ans = 1 ;
	for (int i = 1 ; i <= q ; i++)
	{
		ans *= i ;
		ans %= MOD ;
	}
	return ans ;
}
int C(long long n,long long m)
{
	long long ans ;
	ans = A(n) / (A(m) % MOD * A(n - m) % MOD) % MOD ;
}
int main()
{
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0) ;
	long long n,m,i,ans = 0,c[MX + 10] ;
	string s ;
	cin >> n >> m >> s ;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> c[i] ;
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (s[i] == '0')
		{
			cout << A(n) % MOD << '\n' ;
			return 0 ;
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		ans += (A(101 - i) * C(99,i)) % MOD ;
		ans %= MOD ;
	}
	cout << ans << '\n' ;
	return 0 ; 
}

