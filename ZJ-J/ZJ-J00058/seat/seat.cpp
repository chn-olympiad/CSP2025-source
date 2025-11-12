#include<bits/stdc++.h>
using namespace std;

struct Point{
	int id, num;
}a[105];

struct node{
	int xx, yy;
}ans[105];
int n, m, res;

bool cmp( Point x, Point y )
{
	return x.num > y.num;
}

int main()
{
	
	freopen( "seat.in", "r", stdin );
	freopen( "seat.out", "w", stdout );
	
	cin >> n >> m;
	for( int i = 1; i <= n * m; i ++ )
	{
		a[i].id = i;
		cin >> a[i].num;
	}
	
	sort( a + 1, a + 1 + n * m, cmp );
	for( int i = 1; i <= n * m; i ++ )
	{
		if( a[i].id == 1 ) res = i;
	}
	
	int iy = 1, ix = 0;
	for( int i = 1; i <= n * m; i ++ )
	{
		if( ix == n && iy % 2 == 1 ) 
		{
			iy ++;
			ix = n + 1;
		}else if ( ix == 1 && iy % 2 == 0 )
		{
			iy ++;
			ix = 0;
		}
		if( iy % 2 == 1 ) ix ++;
		if( iy % 2 == 0 ) ix --;
		
		ans[i].xx = ix;
		ans[i].yy = iy;
	}
	
	cout << ans[res].yy << " " << ans[res].xx;
	
	
	return 0;
}

//3 3
//94 95 96 97 98 99 100 93 92
