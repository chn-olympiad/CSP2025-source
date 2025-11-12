#include<bits/stdc++.h>
using namespace std ;
char Str[100005] ;
long long len ;
unsigned long long Num[12] ;
bool flag = 0 ;
int main() {
	freopen ( "number.in" , "r" , stdin ) ;
	freopen ( "number.out" , "w" , stdout ) ;
	memset ( Num , 0 , sizeof ( Num ) ) ;
	cin >> Str ;
	len = sizeof ( Str ) ;
	for ( unsigned long long i = 0 ; i < len ; i++ ) {
		if ( Str[i] >= '0' && Str[i] <= '9' ) {
			Num[ Str[i] - '0' ] ++ ;
		}
	}
	for ( int i = 9 ; i >= 0 ; i-- ) {
		if ( flag == 0 && i == 0 ) {
			cout << 0 ;
			return 0 ;
		}
		if ( Num[i] > 0 ) {
			flag = 1 ;
			for ( int k = 0 ; k < Num[i] ; k++ ) {
				cout << i ;
			}
		} 
	}
	if ( flag == 0 ) {
		cout << 0 ;
	}
	return 0 ;
} 
