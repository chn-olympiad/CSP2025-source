#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,tl,ans;
int a[1001],b[1001][1001],c[1001][3];
int main()
{
	freopen( "xor.in" , "r" , stdin );
	freopen( "xor.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> n >> k;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[i];
	}
	for ( int lp = 1 ; lp <= n ; lp ++ )
	{
		for ( int rp = lp ; rp <= n ; rp ++ )
		{
			b[lp][rp] = b[lp][rp - 1] ^ a[rp];
		}
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		for ( int j = i ; j <= n ; j ++ )
		{
			if ( b[i][j] == k )
			{
				cnt ++;
				c[cnt][1] = i;
				c[cnt][2] = j;
				break;
			}
		}
	}
	ans = cnt;
	if ( ans == 0 )
	{
		cout << 0;
		return 0;
	}
	tl = c[1][2];
	for ( int i = 2 ; i <= cnt ; i ++ )
	{
		if ( c[i][1] <= tl )
		{
			ans --;
		}
		else
		{
			tl = c[i][2];
		}
	}
	cout << ans;
	return 0;
}
/***********************
Written by zbm TJ-J00446.
2025/11/1.
***********************/ 
