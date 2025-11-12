#include <bits/stdc++.h>
using namespace std ;
int n , a[5100] ;
int ww = 998244353 ;
int cc(int q1 , int q2)
{
	int shang = 1 ;
	for (int i = 1 ; i <= q2 ; i++)
	{
		shang = (shang * (q1 - i + 1)) % ww ;
	}
	int xia = 1 ;
	for (int i = 1 ; i <= q2 ; i++)
	{
		xia = (xia * (q2 - i + 1)) % ww ;
	}
	return shang / xia ;
}
int main()
{
	freopen("polygon.in" , "r" , stdin) ;
	freopen("polygon.out" , "w" , stdout) ;
	cin >> n ;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] ;
	}
	sort(a + 1 , a + n + 1 , greater<int>()) ;
	if (a[1] == 1)
	{
		long long ans = 0 ;
		for (int i = 3 ; i <= n ; i++)
		{
			ans = (ans + cc(n , i)) % ww ;
		}
		cout << ans ;
		return 0 ;
	}
	if (n == 3)
	{
		if (a[2] + a[3] > a[1])
		{
			cout << 1 ;
		}
		else
		{
			cout << 0 ;
		}
		return 0 ;
	}
	return 0 ;
}

