#include <bits/stdc++.h>
using namespace std ;
string s ;
int a[1000100] , la = 1 ;
int main()
{
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
	cin >> s ;
	int n = s.length() ;
	for (int i = 0 ; i < n ; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[la] = s[i] - '0' ;
			/*
			cout << a[la] << endl ;
			*/
			la++ ;
		}
	}
	sort(a + 1 , a + la) ;
	/*
	for (int i = 1 ; i < la ; i++)
	{
		cout << a[i] ;
	}
	cout << endl ;
	*/
	for (int i = la - 1 ; i >= 1 ; i--)
	{
		cout << a[i] ;
	}
	return 0 ;
}

