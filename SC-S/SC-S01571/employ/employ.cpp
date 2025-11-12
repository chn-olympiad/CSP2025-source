#include<bits/stdc++.h>
using namespace std ;
int n , m , mod = 998244353;
string s ;
int c[510] , res ;
long long f[510] ;
bool vis[510] ;
void dfs(int x , int sum , int cnt)
{
	if(x == n + 1)
	{
		if(cnt >= m) res ++ ;
		return ;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if((sum >= c[i] || s[i - 1] == '0')&& vis[i] == false )
		{
			vis[i] = true ;
			dfs(x + 1 , sum + 1 , cnt) ;
			vis[i] = false ;
		}
		else if(vis[i] == false && s[i - 1 ] == '1')
		{
			vis[i] = true ;
			dfs(x + 1 , sum , cnt + 1) ;
			vis[i] = false ;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out", "w" , stdout) ;
	cin >> n >> m ;
	cin >> s ;
	int cs = n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		 cin >> c[i] ;
	} 
	dfs(1 , 0 , 0);
	cout << res ;
	return 0 ;
}