#include <bits/stdc++.h>
using namespace std ;
int T ;
struct qqq
{
	int a , b , c ;
} ;
struct ppp
{
	int q , id ;
	int dn , dv ;
} ;
bool cmp(ppp x , ppp y)
{
	return x.dv < y.dv ;
}
int main()
{
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	cin >> T ;
	for (int t = 1 ; t <= T ; t++)
	{
		int n ;
		qqq a[100100] ;
		cin >> n ;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c ;
		}
		ppp q1[100100] , q2[100100] , q3[100100] ;
		int l1 = 1 , l2 = 1 , l3 = 1 ;
		for (int i = 1 ; i <= n ; i++)
		{
			if (a[i].a >= max(a[i].b , a[i].c))
			{
				q1[l1].q = a[i].a ;
				q1[l1].id = i ;
				if (a[i].b >= a[i].c)
				{
					q1[l1].dn = 2 ;
					q1[l1].dv = a[i].a - a[i].b ;
				}
				else
				{
					q1[l1].dn = 3 ;
					q1[l1].dv = a[i].a - a[i].c ;
				}
				l1++ ;
			}
			else if (a[i].b >= max(a[i].a , a[i].c))
			{
				q2[l2].q = a[i].b ;
				q2[l2].id = i ;
				if (a[i].a >= a[i].c)
				{
					q2[l2].dn = 1 ;
					q2[l2].dv = a[i].b - a[i].a ;
				}
				else
				{
					q2[l2].dn = 3 ;
					q2[l2].dv = a[i].b - a[i].c ;
				}
				l2++ ;
			}
			else if (a[i].c >= max(a[i].a , a[i].b))
			{
				q3[l3].q = a[i].c ;
				q3[l3].id = i ;
				if (a[i].a >= a[i].b)
				{
					q3[l3].dn = 1 ;
					q3[l3].dv = a[i].c - a[i].a ;
				}
				else
				{
					q3[l3].dn = 2 ;
					q3[l3].dv = a[i].c - a[i].b ;
				}
				l3++ ;
			}
		}
		int ans = 0 ;
		
		
		
		
		
		
		if (l1 > n / 2)
		{
			sort(q1 + 1 , q1 + l1 , cmp) ;
			int xu = l1 - n / 2 ;
			for (int i = 1 ; i <= xu ; i++)
			{
				if (q1[i].dn == 2)
				{
					q2[l2].q = a[q1[i].id].b ;
					q2[l2].id = q1[i].id ;
					q2[l2].dn = 3 ;
					q2[l2].dv = a[q1[i].id].b - a[q1[i].id].c ;
					l2++ ;
				}
				else if (q1[i].dn == 3)
				{
					q3[l3].q = a[q1[i].id].c ;
					q3[l3].id = q1[i].id ;
					q3[l3].dn = 2 ;
					q3[l3].dv = a[q1[i].id].c - a[q1[i].id].b ;
					l3++ ;
				}
			}
			for (int i = xu + 1 ; i < l1 ; i++)
			{
				ans += q1[i].q ;
			}
			if (l2 > n / 2)
			{
				sort(q2 + 1 , q2 + l2 , cmp) ;
				int xu2 = l2 - n / 2 ;
				for (int i = 1 ; i <= xu2 ; i++)
				{
					ans += a[q2[i].id].c ;
				}
				for (int i = xu2 + 1 ; i < l2 ; i++)
				{
					ans += q2[i].q ;
				}
				for (int i = 1 ; i < l3 ; i++)
				{
					ans += q3[i].q ;
				}
				cout << ans << endl ;
				continue ;
			}
			if (l3 > n / 2)
			{
				sort(q3 + 1 , q3 + l3 , cmp) ;
				int xu2 = l3 - n / 2 ;
				for (int i = 1 ; i <= xu2 ; i++)
				{
					ans += a[q3[i].id].b ;
				}
				for (int i = xu2 + 1 ; i < l3 ; i++)
				{
					ans += q3[i].q ;
				}
				for (int i = 1 ; i < l2 ; i++)
				{
					ans += q2[i].q ;
				}
				cout << ans << endl ;
				continue ;
			}
		}
		
		
		
		
		
		
		if (l2 > n / 2)
		{
			sort(q2 + 1 , q2 + l2 , cmp) ;
			int xu = l2 - n / 2 ;
			for (int i = 1 ; i <= xu ; i++)
			{
				if (q2[i].dn == 1)
				{
					q1[l1].q = a[q2[i].id].a ;
					q1[l1].id = q2[i].id ;
					q1[l1].dn = 3 ;
					q1[l1].dv = a[q2[i].id].a - a[q2[i].id].c ;
					l1++ ;
				}
				else if (q1[i].dn == 3)
				{
					q3[l3].q = a[q2[i].id].c ;
					q3[l3].id = q2[i].id ;
					q3[l3].dn = 1 ;
					q3[l3].dv = a[q2[i].id].c - a[q2[i].id].a ;
					l3++ ;
				}
			}
			for (int i = xu + 1 ; i < l2 ; i++)
			{
				ans += q2[i].q ;
			}
			if (l1 > n / 2)
			{
				sort(q1 + 1 , q1 + l1 , cmp) ;
				int xu2 = l1 - n / 2 ;
				for (int i = 1 ; i <= xu2 ; i++)
				{
					ans += a[q1[i].id].c ;
				}
				for (int i = xu2 + 1 ; i < l1 ; i++)
				{
					ans += q1[i].q ;
				}
				for (int i = 1 ; i < l3 ; i++)
				{
					ans += q3[i].q ;
				}
				cout << ans << endl ;
				continue ;
			}
			if (l3 > n / 2)
			{
				sort(q3 + 1 , q3 + l3 , cmp) ;
				int xu2 = l3 - n / 2 ;
				for (int i = 1 ; i <= xu2 ; i++)
				{
					ans += a[q3[i].id].a ;
				}
				for (int i = xu2 + 1 ; i < l3 ; i++)
				{
					ans += q3[i].q ;
				}
				for (int i = 1 ; i < l1 ; i++)
				{
					ans += q1[i].q ;
				}
				cout << ans << endl ;
				continue ;
			}
		}
		
		
		
		
		
		
		if (l3 > n / 2)
		{
			sort(q3 + 1 , q3 + l3 , cmp) ;
			int xu = l3 - n / 2 ;
			for (int i = 1 ; i <= xu ; i++)
			{
				if (q3[i].dn == 1)
				{
					q1[l1].q = a[q3[i].id].a ;
					q1[l1].id = q3[i].id ;
					q1[l1].dn = 2 ;
					q1[l1].dv = a[q3[i].id].a - a[q3[i].id].b ;
					l1++ ;
				}
				else if (q1[i].dn == 2)
				{
					q2[l2].q = a[q3[i].id].b ;
					q2[l2].id = q3[i].id ;
					q2[l2].dn = 1 ;
					q2[l2].dv = a[q3[i].id].b - a[q3[i].id].a ;
					l2++ ;
				}
			}
			for (int i = xu + 1 ; i < l3 ; i++)
			{
				ans += q3[i].q ;
			}
			if (l1 > n / 2)
			{
				sort(q1 + 1 , q1 + l1 , cmp) ;
				int xu2 = l1 - n / 2 ;
				for (int i = 1 ; i <= xu2 ; i++)
				{
					ans += a[q1[i].id].b ;
				}
				for (int i = xu2 + 1 ; i < l1 ; i++)
				{
					ans += q1[i].q ;
				}
				for (int i = 1 ; i < l2 ; i++)
				{
					ans += q2[i].q ;
				}
				cout << ans << endl ;
				continue ;
			}
			if (l2 > n / 2)
			{
				sort(q2 + 1 , q2 + l2 , cmp) ;
				int xu2 = l2 - n / 2 ;
				for (int i = 1 ; i <= xu2 ; i++)
				{
					ans += a[q2[i].id].a ;
				}
				for (int i = xu2 + 1 ; i < l2 ; i++)
				{
					ans += q2[i].q ;
				}
				for (int i = 1 ; i < l1 ; i++)
				{
					ans += q1[i].q ;
				}
				cout << ans << endl ;
				continue ;
			}
		}
	}
	return 0 ;
}

