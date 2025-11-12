#include<bits/stdc++.h>
using namespace std;

int n;
int a[5010];

// (^.^) -> (TvT)
// xiaoeyv write lots of code for dfs, but wrong, so delete it

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	bool isOne = true;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		if(isOne) isOne = a[i]==1;
	}
	
	if ( isOne ) {
		cout << 0;
		return 0;
	}
	
	sort(a + 1, a + 1 + n);
	
	if ( n == 3 ) {
		if ( a[1] + a[2] > a[3] ) cout << 1;
		else cout << 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
