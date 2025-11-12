#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+5;
char s[N];
int a[N];
int cnt;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	for ( int i = 0 ; i < strlen(s) ; i ++ )
		if ( isdigit(s[i]) )
			a[ ++ cnt ] = s[i] - '0';

	stable_sort( a + 1, a + cnt + 1 );

	for ( int i = cnt ; i >= 1 ; i -- )
		cout << a[i];

	return 0;
}
