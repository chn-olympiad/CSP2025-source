#include <bits/stdc++.h>
using namespace std;
int n,ans,mx,sum,sm,cnt;
int st[5001];
void dfs( int step )
{
	if ( step > n )
	{
		if ( mx * 2 < sm && cnt >= 3 )
		{
			ans ++;
		}
		return;
	}
	dfs( step + 1 );
	cnt ++;
	int t = mx;
	mx = max( mx , st[step] );
	sm += st[step];
	dfs( step + 1 );
	sm -= st[step];
	mx = t;
	cnt --;
	return;
}
int main()
{
	freopen( "polygon.in" , "r" , stdin );
	freopen( "polygon.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> n;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> st[i];
		sum += st[i];
	}
	dfs( 1 );
	cout << ans;
	return 0;
}
/***********************
Written by zbm TJ-J00446.
2025/11/1.
***********************/
