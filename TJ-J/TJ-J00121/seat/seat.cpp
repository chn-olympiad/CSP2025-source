#include <bits/stdc++.h>
using namespace std ;
int n , m , a[120] ;
int main()
{
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n*m ; i++)
	{
		cin >> a[i] ;
	}
	int k = a[1] ;
	sort(a + 1 , a + n*m + 1 , greater<int>()) ;
	int o1 , o2 ;
	for (int i = 1 ; i <= n*m ; i++)
	{
		if (a[i] == k)
		{
			if (i % n != 0)
			{
				o1 = i / n + 1 ;
				o2 = i % n ;
			}
			else
			{
				o1 = i / n ;
				o2 = n ;
			}
			break ;
		}
	}
	if (o1 % 2 == 1)
	{
		cout << o1 << " " << o2 ;
	}
	else
	{
		cout << o1 << " " << n + 1 - o2 ;
	}
	return 0 ;
}

