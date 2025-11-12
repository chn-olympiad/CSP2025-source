#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
const long long int mo = 998244353;
int c[500];
long long int ans;
string s;
int main()
{
	freopen( "employ.in" , "r" , stdin );
	freopen( "employ.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> n >> m;
	cin >> s;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> c[i];
		if  ( c[i] ) cnt ++;
	}
	ans = 1;
	for ( int i = 1 ; i <= cnt ; i ++ )
	{
		ans *= i;
		ans %= mo;
	}
	cout << ans;
	return 0;
}
/************************
Written by zbm TJ-S00267. 
2020/11/1.
************************/
