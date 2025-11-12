#include<bits/stdc++.h>
using namespace std;
int a[ 5010 ];
int b[ 5010 ];
const int P = 998244353;
long long n;
long long tot = 0;
void ddd( int i , int to , int ma , int cnt ){
	if( i == n + 1 ){
		if( cnt >= 3 && to > 2 * ma )tot ++;
		return ;
	}
	ddd( i + 1 , to , ma , cnt );
	ddd( i + 1 , to + a[ i ] , max( ma , a[ i ] ) , cnt + 1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++ ){
		cin >> a[ i ];
	}
	ddd( 1 , 0 , 0 , 0 );
	cout << tot; 
	return 0;
}
