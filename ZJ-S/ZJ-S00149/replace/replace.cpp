#include<bits/stdc++.h>
using namespace std;
struct ddd{
	int xa1,xb,xa2;
	int ya1,yb,ya2;
}pp[ 200010 ];
bool cmp( ddd a , ddd b ){
	return a.t1.size() > b.t1.size();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	int n , q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++ ){
		string a,b;
		cin >> a >> b;
		int t1,t2;
		bool f = 0;
		for(int j = 0 ; j < b.size() ; j ++ ){
			if( !f ) t1 ++;
			if( f ) t2 ++;
			if( a[ j ] == 'b'){
				pp[ i ].xb = j;
				f = 1;
				t1 --;
			}
		}
		pp[ i ].xa1 = t1;
		pp[ i ].xa2 = t2;
		t1 = 0;
		t2 = 0;
		f = 0;
		for(int j = 0 ; j < b.size() ; j ++ ){
			if( !f ) t1 ++;
			if( f ) t2 ++;
			if( b[ j ] == 'b'){
				pp[ i ].yb = j;
				f = 1;
				t1 --;
			}
		}
		pp[ i ].ya1 = t1;
		pp[ i ].ya2 = t2;
	}
	while( q -- ){
		string s1,s2;
		cin >> s1 >> s2;
		long long tot = 0;
		int op = 0;
		int ta1 = 0;
		int ta2 = 0;
		bool f = 0;
		for(int i = 0 ; i < s2.size() ; i ++ ){
			if( !f )ta1 ++;
			if( f )ta2 ++;
			if( s2[ i ] == 'b'){
				op = i;f = 1;ta1 --;
			}
		}
		int tb1 = 0;
		int tb2 = 0;
		f = 0;
		for(int i = 0 ; i < s1.size() ; i ++ ){
			if( !f )tb1 ++;
			if( f )tb2 ++;
			if( s1[ i ] == 'b'){
				op = i;f = 1;tb1 --;
			}
		}
		for(int i = 1 ; i <= n ; i ++ ){
			if( tb1 - pp[ i ].xa1 + pp[ i ].ya1 == ta1 && tb2 - pp[ i ].xa2 + pp[ i ].ya2 == ta2 && tb1 - pp[ i ].xa1 >= 0 && tb2 - pp[ i ].xa2 >= 0 )tot ++;
		}
		cout << tot << '\n';
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
