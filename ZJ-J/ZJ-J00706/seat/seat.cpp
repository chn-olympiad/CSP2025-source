#include <bits/stdc++.h>
using namespace std;
int n , m , a[10001];
int main(){
	freopen("seat.in" , "r" , stdin );
	freopen("seat.out" , "w" , stdout );
	cin >> n >> m;
	for ( int i = 1; i <= n*m; i++ )	cin >> a[i];
	int q = a[1] , p;
	sort( a+1 , a+n*m+1 , greater<int>() );
	for ( int i = 1; i <= n*m; i++ ){
		if ( a[i] == q ){
			p = i;
			break;
		}
	}
	int x , y;
	if ( p % n > 0 )	x = p / n + 1;
	else	x = p / n;
	if ( p % n == 0 )	p = n;
	else p = p % n;
	if ( x % 2 == 1 )	y = p;
	else	y = n - p + 1;
	cout << x << " " << y << endl;
	return 0;
}
