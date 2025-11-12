//SN-J00891  耿峥钊  西安辅轮中学 
#include <bits/stdc++.h>
using namespace std ;
int s[20][20] , a[10005] ,k[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m , num = 1, num1 = 1;
	cin >> n >> m ;
	for (int i = 1 ; i <= m ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			cin >> s[i][j] ;
		}
	}
	int r = s[1][1] ;
	for (int i = 1 ; i <= m ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			a[num] += s[i][j] ;
			num++ ;
		}
	}
	sort(a + 1 , a + n + 1) ;
	for (int i = 1 ; i <= m ; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1 ; j <= n ; i++)
			{
				k[i][j] += a[num1] ;
				num1++ ;
			}
		}
		else
		{
			for (int j = n ; j >= 1 ; i--)
			{
				k[i][j] += a[num1] ;
				num1++ ;
			}
		}
	}
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			if (s[i][j] == r)
			{
				cout << i << " " << j ;
			}
		}
	}
	return 0 ;
}
