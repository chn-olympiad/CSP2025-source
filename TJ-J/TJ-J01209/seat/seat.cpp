#include <bits/stdc++.h>
using namespace std ;

int n,m,a[10000],b,p,d,cnt,c,r ;
bool cmp(int x, int y)
{
	return x > y ;
}

int main()
{
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n * m ; i ++)
	{
		cin >> a[i] ;
		if(i == 1)
		{
			b = a[i] ;
		}
	}
	sort(a+1,a+n*m+1,cmp) ;
	for(int i = 1 ; i <= n*m ; i ++)
	{
		if(a[i] == b)
		{
			p = i ;
		}
	}
	c = p / n ;
	if(p % n != 0)
	{
		c ++ ;
	}
	else
	{
		if(c % 2 == 0)
		{
			cout << c << " " << '1' ; 
			return 0 ;
		}
		else
		{
			cout << c << " " << n ;
			return 0 ;
		}
	}
	if(c % 2 == 1)
	{
		r = p % n ;
	}
	else
	{
		r = n - (p % n) ;	
	}	
	cout << c << " " << r ;
	return 0 ;
}
