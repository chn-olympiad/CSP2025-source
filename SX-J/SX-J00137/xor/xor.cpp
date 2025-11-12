#include<bits/stdc++.h>
using namespace std;

int n , k , ans;
int a[500005];
int dp[1000][1000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> k;
	for( int i = 1 ; i <= n ; i++ )cin >> a[i];
	if( k == 0 ){
		int x = 0;
		for( int i = 1 ; i <= n ; i++ ){
			if( a[i] == 1 )x++;
			if( x == 2 ){
				ans++;
				x = 0;
			}
		}
	}else if( k == 1 ){
		for( int i = 1 ; i <= n ; i++ ){
			if( a[i] == 1 )ans++;
		}
	}
	cout << ans;
}