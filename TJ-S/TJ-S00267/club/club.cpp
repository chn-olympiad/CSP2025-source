#include <bits/stdc++.h>
using namespace std;
int n,T,cnta,cntb,cntc,ans;
struct xcy
{
	int a,b,c,mx;
	bool hpa,hpb,hpc;
}mb[100001];
int bm[100001];
bool cmp( xcy x , xcy y )
{
	return x.mx > y.mx;
}
int fp( int i )
{
	if ( i > n ) return 0;
	if ( bm[i] ) return bm[i];
	if ( mb[i].hpa && ( ! mb[i].hpb ) && ( ! mb[i].hpc ) )
	{
		if ( cnta * 2 < n )
		{
			cnta ++;
			return 1;
		}
		else
		{
			if ( mb[i].b > mb[i].c )
			{
				cntb ++;
				return 2;
			}
			else
			{
				cntc ++;
				return 3;
			}
		}
	}
	if ( mb[i].hpb && ( ! mb[i].hpa ) && ( ! mb[i].hpc ) )
	{
		if ( cntb * 2 < n )
		{
			cntb ++;
			return 2;
		}
		else
		{
			if ( mb[i].a > mb[i].c )
			{
				cnta ++;
				return 1;
			}
			else
			{
				cntc ++;
				return 3;
			}
		}
	}
	if ( mb[i].hpc && ( ! mb[i].hpb ) && ( ! mb[i].hpa ) )
	{
		if ( cntc * 2 < n )
		{
			cntc ++;
			return 3;
		}
		else
		{
			if ( mb[i].b > mb[i].a )
			{
				cntb ++;
				return 2;
			}
			else
			{
				cnta ++;
				return 1;
			}
		}
	}
	if ( mb[i].hpa && mb[i].hpb && ( ! mb[i].hpc ) )
	{
		if ( cnta < cntb )
		{
			cnta ++;
			return 1;
		}
		else
		{
			cntb ++;
			return 2;
		}
	}
	if ( mb[i].hpa && mb[i].hpc && ( ! mb[i].hpb ) )
	{
		if ( cnta < cntc )
		{
			cnta ++;
			return 1;
		}
		else
		{
			cntc ++;
			return 3;
		}
	}
	if ( mb[i].hpc && mb[i].hpb && ( ! mb[i].hpa ) )
	{
		if ( cntc < cntb )
		{
			cntc ++;
			return 3;
		}
		else
		{
			cntb ++;
			return 2;
		}
	}
	cnta ++;
	return 1;
}
int main()
{
	freopen( "club.in" , "r" , stdin );
	freopen( "club.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> T;
	while( T -- )
	{
		cin >> n;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			cin >> mb[i].a >> mb[i].b >> mb[i].c;
			mb[i].mx = max( mb[i].a , max( mb[i].b , mb[i].c ) );
			if ( mb[i].mx == mb[i].a ) mb[i].hpa = true;
			if ( mb[i].mx == mb[i].b ) mb[i].hpb = true;
			if ( mb[i].mx == mb[i].c ) mb[i].hpc = true;
		}
		sort( mb + 1 , mb + 1 + n , cmp );
		memset( bm , 0 , sizeof bm );
		for ( int i = 1 ; i <= n ; i ++ )
		{
			bm[i] = fp( i );
		}
		ans = 0;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			if ( bm[i] == 1 )
			{
				ans += mb[i].a;
				cout << 1;
			}
			if ( bm[i] == 2 )
			{
				ans += mb[i].b;
				cout << 2;
			}
			if ( bm[i] == 3 )
			{
				ans += mb[i].c;
				cout << 3;
			}
			cout << ' ';
			cout << bm[i] << ' ' << mb[i].a << mb[i].b << mb[i].c << ' ' << ans << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
/************************
Written by zbm TJ-S00267. 
2020/11/1.
************************/
