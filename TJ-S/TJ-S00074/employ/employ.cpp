#include <bits/stdc++.h>
using namespace std ;
int ww = 998244353 ;
int main()
{
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out" , "w" , stdout) ;
	int n , m ;
	cin >> n >> m ;
	string s ;
	cin >> s ;
	int c[600] ;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> c[i] ;
	}
	int ans = 1 ;
	for (int i = 1 ; i <= n ; i++)
	{
		ans = ans * i % ww ;
	}
	cout << ans ;
	return 0 ;
}

