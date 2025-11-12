#include<bits/stdc++.h> 
using namespace std ;
#define q_q return 0

const int N = 1e6 + 10 ;

struct NODE
{
	int a[3] ;
	int tmp ;
}	t[N] ;

int n, ans ;

signed main()
{
	freopen( "club.in", "r", stdin ) ;
	freopen( "club.out", "w", stdout ) ;
	
	ios_base::sync_with_stdio( false ) ;
	cin.tie( nullptr ) ;	cout.tie( nullptr ) ;
	
	int qwq ;	cin >> qwq ;
	
	while( qwq-- )
	{
		ans = 0 ;
		
		cin >> n ;
		
		for(int i=1; i<=n; i++)	cin >> t[i].a[0] >> t[i].a[1] >> t[i].a[2] ;
		
		for(int i=0; i<3; i++)
		{
			for(int j=1; j<=n; j++)
			{
				t[j].tmp = -1e9 ;
				for(int k=0; k<3; k++)	if( k != i )	t[j].tmp = max( t[j].tmp, t[j].a[k] - t[j].a[i] ) ;
			}
			sort( t + 1, t + 1 + n, []( const NODE& a, const NODE& b )
			{
				return a.tmp > b.tmp ;
			} ) ;
			int tot = 0 ;
			for(int j=1; j<=n/2; j++)	tot += t[j].tmp ;
			for(int j=1; j<=n; j++)		tot += t[j].a[i] ;
			ans = max( ans, tot ) ;
		}
		
		int sum[3] = { }, tot = 0 ;
		bool flag = false ;
		for(int i=1; i<=n; i++)
		{
			int p = 0 ;
			if( t[i].a[1] > t[i].a[p] )	p = 1 ;
			if( t[i].a[2] > t[i].a[p] )	p = 2 ;
			tot += t[i].a[p] ;
			if( ++sum[p] > n / 2 )
			{
				flag = true ;
				break ;
			}
		}
		cout << ( flag ? ans : max( ans, tot ) ) << endl ;
	}
	
	q_q ;
}
//	oldmoon:(
//	  |    |---|
//	--|--  |   |
//	  |    |---|
//	|---|  |   |
//	|   |  |---|
//	|---| /    |