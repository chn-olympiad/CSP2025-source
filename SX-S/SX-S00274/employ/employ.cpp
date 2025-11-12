#include <bits/stdc++.h>
using namespace std;
int c[505];
long long ans = 1;
int n, m;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> c[i];
	for ( int i = n ; i > m ; i -- ) {
		ans *= i;
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}