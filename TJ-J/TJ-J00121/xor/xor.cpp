#include <bits/stdc++.h>
using namespace std ;
int n , k , a[500100] ;
int main()
{
	freopen("xor.in" , "r" , stdin) ;
	freopen("xor.out" , "w" , stdout) ;
	cin >> n >> k ;
	int f = 1 ;
	int num0 = 0 , num1 = 0 ;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] ;
		if (a[i] != 1)
		{
			f = 0 ;
		}
		if (a[i] == 0)
		{
			num0++ ;
		}
		if (a[i] == 1)
		{
			num1++ ;
		}
	}
	if (n == 1 && k == 0 && a[1] == 1)
	{
		cout << 0 ;
		return 0 ;
	}
	if (n == 2 && k == 0 && a[1] == 1 && a[2] == 1)
	{
		cout << 1 ;
		return 0 ;
	}
	if (k == 0 && f == 1)
	{
		cout << n / 2 ;
		return 0 ;
	}
	if (k == 0 && num0 + num1 == n)
	{
		int ans = num0 ;
		for (int i = 1 ; i <= n ; i++)
		{
			if (a[i] == 1)
			{
				int ll = 0 ;
				while (a[i] == 1)
				{
					ll++ ;
					i++ ;
				}
				ans = ans + ll / 2 ;
				i-- ;
			}
		}
		cout << ans ;
		return 0 ;
	}
	if (k == 1 && num0 + num1 == n)
	{
		cout << num1 ;
		return 0 ;
	}
	return 0 ;
}

