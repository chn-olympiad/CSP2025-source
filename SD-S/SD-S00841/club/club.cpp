#include<bits/stdc++.h>
using namespace std;

#define il inline
#define int long long
#define N 100010

bool tes1;

int T, n, a[N][3], num[3], res;
priority_queue <int, vector<int>, greater<int>> q[3];

bool tes2;

il void reset()
{
	res = 0;
	for( int i = 0; i <= 2; i ++ )
	{
		num[i] = 0;
		while( !q[i].empty() ) q[i].pop();
	}
}

signed main()
{
//	cout << (&tes1 - &tes2) / 1024 / 1024 << endl;
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	freopen( "club.in", "r", stdin );
	freopen( "club.out", "w", stdout );
	cin >> T;
	while( T -- )
	{
		cin >> n; reset();
		for( int i = 1; i <= n; i ++ )
			for( int j = 0; j <= 2; j ++ ) cin >> a[i][j];
		for( int i = 1, mx, id, sec; i <= n; i ++ )
		{
			mx = sec = 0;
			for( int j = 0; j <= 2; j ++ )
			{
				if( a[i][j] > mx ) sec = mx, mx = a[i][j], id = j;
				else sec = max( sec, a[i][j] );
			}
			res += mx; num[id] ++; q[id].push( mx - sec );
		}
		int flag = -1;
		for( int i = 0; i <= 2; i ++ )
			if( num[i] * 2 > n ) flag = i;
		if( flag != -1 )
		{
			while( num[flag] * 2 > n )
			{
				res -= q[flag].top(); q[flag].pop();
				num[flag] --;
			}
		}
		cout << res << '\n';
	}
//	cout << clock() << endl;
	return 0;
} 
