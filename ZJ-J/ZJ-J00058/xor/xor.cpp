#include<bits/stdc++.h>
using namespace std;

const int N = 500005;

struct Point{
	int l, r;
}ans[1000005];
int n, k, a[N], pre[N], vis[N], cnt = 0, _ = 0;
bool flaga = true, flagb = true;

bool cmp( Point x, Point y )
{
	if( x.l == y.l ) return x.r < y.r;
	return x.l < y.l;
}

queue< int > que;

int main()
{
	
	freopen( "xor.in", "r", stdin );
	freopen( "xor.out", "w", stdout );
	
	cin >> n >> k;
	for( int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		flaga &= ( a[i] == 1 );
		flagb &= ( a[i] == 1 || a[i] == 0 );
	}
	for( int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] ^ a[i];

    if( k == 0 && flaga )
    {
    	cout << n / 2;
    	return 0;
	}
	cout << ( flagb && k == 1 ) << endl;
	if( flagb && k == 1 )
	{
		int res = 0;
		for( int i = 1; i <= n; i ++ )
		{
			if( a[i] == 1 ) res ++;
		}
		cout << res;
		return 0;
	}
	if( flagb && k == 0 )
	{
		a[n + 1] = 0;
		int res = 0;
		for( int i = 1; i <= n; i ++ )
		{
			if( a[i] == 0 ) res ++;
			if( a[i] == 1 && a[i + 1] == 1 ) 
			{
				res ++;
				i ++;
			}
		}
		cout << res;
		return 0;
	}
	
	for( int i = 1; i <= n; i ++ )
	{
		for( int j = 0; j < i; j ++ )
		{
			if( ( int )( pre[i] ^ pre[j] ) == k ) 
			{
				cnt ++;
				ans[cnt].l = j + 1;
				ans[cnt].r = i;
			}
		}
	}
	
	sort( ans + 1, ans + 1 + cnt, cmp );
	
	for( int j = 1; j <= cnt; j ++ )
	{
		while( que.size() ) que.pop();
		que.push( ans[j].r ); int res = 1;
		for( int i = 1; i <= cnt; i ++ )
		{
			if( ans[i].l > que.front() ) 
			{
				que.pop();
				que.push( ans[i].r );
				res ++;
			}
		}
		_ = max( res, _ );
	}

	
	cout << _;
	
	

	
	
	return 0;
}

//100 1
//1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

