#include<bits/stdc++.h>
#define ll int
using namespace std;
ll n , m ;
ll a[500] = {0} ;
bool c( ll a , ll b ){
	return a > b ;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m ;
	for( ll i = 1 ; i <= n * m ; i++ ){
		cin >> a[i];
	}
	ll b = a[1] , bb = 0 ;
	sort(a+1,a+n*m+1,c);
	for( ll i = 1 ; i <= n * m ; i++ ){
		if( a[i] == b ){
			bb = i ;
		}
	}
	ll x = bb / n + 1 ;
	ll y = bb % n - 1 ;
	if( y == -1 ){
		y = n - 1 ;
		x--;
	}
	if( x % 2 == 0 ){
		y=n-y-1; 
	}
	y++;
	cout << x << " " << y << endl ;
} 
	
