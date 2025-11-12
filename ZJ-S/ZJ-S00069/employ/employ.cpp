#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, a[505], vis[505], s[505], ans;
string ss;
void dfs( int d, int em ) {
	if( em >= m ) {
		int fact = 1;
		for(int i=1; i<=n-d+1; i++) fact *= i, fact %= mod ;
		ans += fact;
		ans %= mod;
		return ;
	}
	if( m - em > s[n] - s[d-1] ) return ;
	if( d > n ) {
//		if ( em >= m ) ans ++;
//		ans %= mod;
//		cout<<"ok"<<'\n';
		return ;
	}
	for(int i=1; i<=n; i++) {
		if( vis[i] )continue;
		vis[i] = 1;
//		cout<<"d="<<d<<" em="<<em<<' '<<i<<" a[i]="<<a[i]<<':'<<( ( a[i] >= (d - em) ) && ( ss[d-1] == '1' ) )<<'\n';
		dfs( d + 1, em + ( ( a[i] >= (d - em) ) && ( ss[d-1] == '1' ) ) );
		vis[i] = 0;
	}
	return ;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf( "%d%d", & n, & m );
	cin >> ss;
	for(int i=0; i<ss.size(); i++)s[i+1] = s[i] + ( ss[i] == '1' );//not include i <=> 1~s.size() normal
	for(int i=1; i<=n; i++)scanf( "%d", & a[i] );
	if( n <= 18 ) {
		dfs(1,0);
		printf( "%d", ans );
		return 0;
	}
	cout << 0;
	return 0;
}
