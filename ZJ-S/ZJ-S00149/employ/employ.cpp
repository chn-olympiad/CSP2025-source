#include<bits/stdc++.h>
using namespace std;
int k[ 510 ];
int c[ 510 ];
const int P =  998244353;
bool b[ 510 ];
int n , m;
//int klo = 0;
string s;
vector<int> v;
long long tot = 0;
bool check(){
	int t = 0;
	for(int i = 0 ; i < n ; i ++ ){
		if( s[ i + 1 ] == '1' && i + 1 - t <= c[ v[ i ] ])t ++;
	}
//	klo = max( t , klo );
	if( t >= m )return 1;
	return 0;
}
void ddd(int oo){
	if( oo == n ){
		if( check() )tot ++;
		tot %= P;
		return ;
	}
	for(int i = 1 ; i <= n ; i ++ ){
		if( !b[ i ] ){
			b[ i ] = 1;
			v.push_back( i );
			ddd( oo + 1 );
			v.pop_back();
			b[ i ] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin >> n >> m;
	string p;
	cin >> p;
	s = " " + p;
//	long long tot = 1 , t = 0 , l = 0 ;
	int l = 0;
	bool f = 1;
	for(int i = 1 ; i <= n ; i ++ ){
		cin >> c[ i ];
		if( s[ i ] == '1' ) l ++;
		else f = 0;
	}
	if( l < m ){
		cout << 0;
		return 0;
	}
	ddd( 0 );
	cout << tot ;
	
//	for(int i = 0 ; i < n ; i ++ )cout << v[ i ] << ' ';
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
