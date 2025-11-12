#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int w = 1;
	for ( int i = 1 ; i <= n * m ; i ++ ) {
		cin >> a[i];
		if ( i != 1 && a[i] > a[1] )
			w++;
	}
	int aa = 0;
	int bb = w % n;
	if ( bb != 0 )
		aa++;
	aa += w / n;
	if ( bb == 0 )
		bb = n;
	if ( aa % 2 != 0 )
		cout << aa << " " << bb;
	else
		cout << aa << " " << n - bb + 1;
	return 0;
}
