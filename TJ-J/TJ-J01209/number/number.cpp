#include <bits/stdc++.h>
using namespace std ;
string s ;
long long cnt = 1 , maxn , cnt2 , n , m , p , q = 1 ;
long long a[1000005],b[1000005] ;
bool f = true ;
int main()
{
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	cin >> s ;
	for(int i = 0 ; i <= s.size() - 1 ; i ++) 
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			a[cnt] = s[i] - '0' ;
			cnt ++ ;
		}
	}
	cnt2 = cnt ;
	for(int i = 1 ; i <= cnt2 ; i ++)
	{
		for(int j = 1 ; j < cnt ; j ++)
		{
			if(a[j] > maxn)
			{
				maxn = a[j] ;
				n = j ;
			}
		}
		b[i] = a[n] ;
		if(a[n] == 0)
		{
			b[i] = -1 ;
		}
		a[n] = 0 ;
		maxn = 0 ;
	}
	cnt = 0 ;
	while(f == true)
	{
		if(b[q] != 0)
		{
			cnt ++ ;
			if(b[q] == -1)
			{
				b[q] = 0 ;
			}
		}
		else
		{
			f = false ;
		}
		q ++ ;
	}
	cnt2 = cnt ;
	cnt -= 2 ;
	for(int i = 1 ; i <= cnt2 ; i ++)
	{
		p = b[i] ;
		for(int i = 1 ; i <= cnt ; i ++)
		{
			p *= 10 ;
		}
		m += p ;
		cnt -- ; 
	}
	cout << m ;
	return 0 ; 
}
