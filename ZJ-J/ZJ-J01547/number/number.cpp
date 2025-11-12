#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s ;
ll a[10] , x ;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s ;
	for( ll i = 0 ; i < s.size() ; i++ ){
		if( s[i] >= '0' && s[i] <= '9' ){
			x = s[i] - '0' ;
			a[x]++;
		}
	}
	for( ll i = 9 ; i >= 0 ; i-- ){
		if( a[i] != 0 ){
			for( ll j = 1 ; j <= a[i] ; j++ ){
				cout << i ;
			}
		}
	}
	return 0 ;
}
