#include <bits/stdc++.h>
using namespace std;

int n, m, mp[15][15], a[1000], t, cnt;      // cnt 第几个数

bool cmp( int x, int y ) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for ( int i = 1 ; i <= n * m ; i ++ )
		cin >> a[i];

	t = a[1]; // 小R成绩

	stable_sort( a + 1, a + ( n *m ) + 1, cmp );

	for ( int i = 1 ; i <= m ; i ++ ) { // 列数
		for ( int j = 1 ; j <= n ; j ++ ) // 行数
			mp[j][i] = a[ ++ cnt ];
		for ( int j = n ; j >= 1 ; j --) // 行数
			mp[j][ i + 1 ] = a[ ++ cnt];
		i ++;
	}

	// 找小R
	int ans = 0, ans1 = 0;  // ans : 行  ans1 : 列
	for ( int i = 1; i <= n ; i ++ ) {
		for ( int j = 1; j <= m ; j ++ ) {
			if ( mp[i][j] == t ) {
				ans = i, ans1 = j;
				break;
			}
		}
	}
	cout << ans1 << " " << ans;

	return 0;
}