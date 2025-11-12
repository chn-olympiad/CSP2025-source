//SN-J00891  耿峥钊  西安辅轮中学 
#include <bits/stdc++.h>
using namespace std ;
int a[10005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n , num = 0;
	cin >> n ;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] ;
	}
	for (int i = 3 ; i <= n ; i++)
	{
		for (int k = 1 ; k <= n - 3; k++)
		{	
			int maxn = -1 , sum = 0;
			for (int j = k ; j <= i ; j++)
			{
				maxn = max(maxn,a[j]) ;
				sum += a[j] ;	
			}
			if (sum > 2 * maxn)
			{
				num++ ;
			}
		}
	}
	cout << num ;
	return 0 ;
}
