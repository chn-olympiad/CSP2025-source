#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long int cnt,ans = 114514114514666;
struct ege
{
	int u,v,w;
}a[2000000],b[2000000];
int c[11],fa[10020];
bool usi[11];
bool cmp( ege x , ege y )
{
	return x.w < y.w;
}
int find( int x )
{
	if ( fa[x] == x ) return x;
	return fa[x] = find( fa[x] );
}
void merge( int x , int y )
{
	int fx = find( x );
	int fy = find( y );
	if ( fx != fy )
	{
		fa[fx] = fy;
	}
}
void solve( )
{
	cnt = 0;
	for ( int i = 1 ; i <= n + k ; i ++ )
	{
		fa[i] = i;
	}
	int t = m + n * k;
	for ( int i = 1 ; i <= t ; i ++ )
	{
		b[i].u = 0;
		b[i].v = 0;
		b[i].w = 0;
	}
	for ( int i = 1 ; i <= m ; i ++ )
	{
		b[i] = a[i];
	}
	for ( int i = 1 ; i <= k ; i ++ )
	{
		if ( usi[i] )
		{
			for ( int j = 1 ; j <= n ; j ++ )
			{
				b[m + ( i - 1 ) * n + j] = a[m + ( i - 1 ) * n + j];
			}
			cnt += c[i];
		}
		else
		{
			for ( int j = 1 ; j <= n ; j ++ )
			{
				b[m + ( i - 1 ) * n + j].w = 2147483647;
			}
		}
	}
	sort( b + 1 , b + 1 + m + k * n , cmp );
	for ( int i = 1 ; i <= m + k * n ; i ++ )
	{
		if ( find( b[i].u ) != find( b[i].v ) )
		{
			merge( b[i].u , b[i].v );
			cnt += b[i].w;
		}
	}
	ans = min( ans , cnt );
}
void dfs( int step )
{
	if ( step > k )
	{
		solve( );
		return;
	}
	usi[step] = true;
	dfs( step + 1 );
	usi[step] = false;
	dfs( step + 1 );
}
int main()
{
	freopen( "road4.in" , "r" , stdin );
	freopen( "road.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> n >> m >> k;
	for ( int i = 1 ; i <= m ; i ++ )
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for ( int i = 1 ; i <= k ; i ++ )
	{
		cin >> c[i];
		for ( int j = 1 ; j <= n ; j ++ )
		{
			a[m + ( i - 1 ) * n + j].u = i + n;
			a[m + ( i - 1 ) * n + j].v = j;
			cin >> a[m + ( i - 1 ) * n + j].w;
		}
	}
	dfs( 1 );
	cout << ans;
	return 0;
}
/*************************
Written by zbm TJ-S00267. 
2020/11/1.
*************************/
