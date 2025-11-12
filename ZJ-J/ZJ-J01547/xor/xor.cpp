#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n , cnt1 = 0 , cnt2 = 0 , k ;
ll a[500] = {0} ;
bool c( ll a , ll b ){
	return a > b ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k >> a[1] ;
	for( int i = 2 ; i <= n ; i++ ){
		cin >> a[i];
	}
	int t ;
	for( int i = 1 ; i <= n ; i++ ){
		t=0;
		for( int j = i ; j <= n ; j++ ){
			t^=a[j];
			if( k == t || a[i] == k ){
				cnt1++;
				i=j;
				break;
			}
		}
	}
	for( int i = n ; i >= 1 ; i-- ){
		t=0;
		for( int j = i ; j >= 1 ; j-- ){
			t^=a[j];
			if( k == t || a[i] == k ){
				cnt2++;
				i=j;
				break;
			}
		}
	}
	cout<<max(cnt1,cnt2);
} 
	
