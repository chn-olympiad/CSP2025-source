#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 998244353 ;
ll n , m , cnt = 0 ;
ll a[5000] = {0} , b[5000] = {0} ;
ll find( int x , int i , int tt){
	int tot = 1 ;
	for( int j = 1 ; j < i && tt >= 3 ; j++ ){
		if( a[j] > x ){
			break;
		}
		else{
			tot+=find(x-a[j],j,tt-1);
		}
	} 
	return tot ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	for( ll i = 1 ; i <= n ; i++ ){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for( ll i = 1 ; i <= n ; i++ ){
		b[i]=a[i]+b[i-1];
	}
	for( ll i = 3 ; i <= n ; i++ ){
		if( b[i] > 2 * a[i] ){
			int x = b[i] - 2 * a[i] ;
			cnt=(cnt+find(x-1,i,i-1))%N;
		}
	}
	cout << cnt << endl ; 
} 
	
