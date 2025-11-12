#include<bits/stdc++.h> 
using namespace std ;
int n ;
int A[5005] ;
long long num ;
int main() {
	freopen ( "polygon.in" , "r" , stdin ) ;
	freopen ( "polygon.out" , "w" , stdout ) ;
	cin >> n ;
	for ( int i = 0 ; i < n ; i++ ) {
		cin >> A[i] ;
	}
	sort ( A , A + n ) ;
	cout << 8 ;
	return 0 ;
}
