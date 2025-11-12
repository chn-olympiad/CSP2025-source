#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 10 ;
int n , T , a[N][5] , maxx = 0 , b[N];
bool cmp (int x, int y)
{
	return x > y ;
}
void dfs(int cnt , int sum , int sum1 ,int sum2 , int sum3) 
{
	if(cnt == n + 1) 
	{
		maxx = max(maxx , sum) ;
		return ;
	}
	if(sum1 < n / 2)
	{
		dfs(cnt + 1 , sum + a[cnt][1] ,sum1 + 1 , sum2 ,sum3 ) ;
	}
	if(sum2 < n / 2)
	{
		dfs(cnt + 1 , sum + a[cnt][2] ,sum1 , sum2  + 1,sum3 ) ;
	}
	if(sum3 < n / 2)
	{
		dfs(cnt + 1 , sum + a[cnt][3] ,sum1 , sum2 ,sum3 + 1 ) ;
	}
	return ;
}
int main()
{
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out", "w" , stdout) ;
	cin >> T ; 
	while(T --)
	{
		maxx = 0 ;
		cin >> n ;
		bool f = false ;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> 	a[i][1] >> a[i][2] >> a[i][3] ;
			b[i] = a[i][1] ;
			if(a[i][2] != 0 || a[i][3] != 0) f= true ;
		}
		if(f == false)
		{
			sort(b + 1 , b + 1 + n , cmp);
			for(int i = 1 ; i <= n/2 ; i ++)
			{
				maxx += b[i]; 
			}
			cout << maxx ;
		}
		else
		{
			dfs(1 , 0 , 0 , 0 , 0);
			cout << maxx << endl ;
		}
	}
	return 0 ;
 } 
 /*
 3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 
 
 */