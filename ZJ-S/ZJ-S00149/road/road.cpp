#include<bits/stdc++.h>
using namespace std;
struct ddd{
	int x,y,t;
	bool operator < ( const ddd tmp )const{
		return t < tmp.t;
	}
}p[ 1000010 ];
int ko[ 20 ][ 10010 ];
int c[ 20 ];
priority_queue<ddd> q;
int pre[ 10010 ];
int Find( int x ){
	if( x == pre[ x ] )return x;
	else return pre[ x ] = Find( pre[ x ] );
}
int n , m , k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++ ){
		cin >> p[ i ].x >> p[ i ].y >> p[ i ].t;
		ddd l = p[ i ];
		l.t = -l.t;
		q.push( l );
	}
	for(int i = 1 ; i <= n ; i ++ ){
		pre[ i ] = i;
	}
	if( k == 0 ){
		long long tt = 0;
		while( !q.empty() ){
			ddd k = q.top();
			q.pop();
			int a = Find( k.x );
			int b = Find( k.y );
			if( a != b ){
				tt += -k.t;
				pre[ a ] = b;
			}
		}
		cout << tt;
		return 0;
	}
	for(int i = 1 ; i <= k ; i ++ ){
		cin >> c[ i ];
		for(int j = 1 ; j <= n ; j ++ ){
			cin >> ko[ i ][ j ];
		}
	}
	for(int i = 1 ; i <= k ; i ++ ){
		for(int j = 1 ; j <= n ; j ++ ){
			for(int l = j + 1 ; l <= n ; l ++ ){
				ddd op;
				op.t = -(ko[ i ][ j ] + ko[ i ][ l ]);
				op.x = l;
				op.y = j;
				q.push( op );
			}
		}
	}
		long long tt = 0;
		while( !q.empty() ){
			ddd k = q.top();
			q.pop();
			int a = Find( k.x );
			int b = Find( k.y );
			if( a != b ){
				tt += -k.t;
				pre[ a ] = b;
			}
		}
		cout << tt;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
