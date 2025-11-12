#include<bits/stdc++.h>
using namespace std;

#define N 510
#define il inline
#define int long long
const int mod = 998244353;

int n, m, a[N], b[N];
char s[N];

il void add( int &x, int y ) { x = (x + y) % mod; }

struct sub1 {
	
	int f[(1<<18) + 5][20], res;
	
	il void sol()
	{
		f[0][0] = 1;
		int cnt = 0;
		for( int S = 0; S < (1 << n); S ++ )
		{
			cnt = 0;
			for( int i = 1; i <= n; i ++ )
				if( (S >> (i - 1)) & 1 ) cnt ++;
			for( int j = 0; j <= cnt; j ++ )
			{
				for( int i = 1; i <= n; i ++ )
					if( (S >> (i - 1)) & 1 ) continue;
					else {
						if( j < b[i] && a[cnt + 1] == 1 ) add( f[S | (1 << (i - 1))][j], f[S][j] );
						else add( f[S | (1 << (i - 1))][j + 1], f[S][j] );
					}
			}
		}
		for( int i = m; i <= n; i ++ )
			add( res, f[(1 << n) - 1][n - i] );
		cout << res << endl;
	}
} sub1;

struct sub2 {
	
	il bool chk() { return n == m; }
	
	il void sol()
	{
		for( int i = 1; i <= n; i ++ )
			if( a[i] == 0 || b[i] == 0 ) return cout << 0 << endl, void();
		int res = 1;
		for( int i = 1; i <= n; i ++ ) res = res * i % mod;
		cout << res << endl;
	}
} sub2;

signed main()
{
	freopen( "employ.in", "r", stdin );
	freopen( "employ.out", "w", stdout );
	cin >> n >> m >> (s + 1);
	for( int i = 1; i <= n; i ++ ) a[i] = s[i] - '0';
	for( int i = 1; i <= n; i ++ ) cin >> b[i];
	if( n <= 18 ) sub1.sol();
	else if( sub2.chk() ) sub2.sol();
	return 0;
}
