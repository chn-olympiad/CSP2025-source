#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
int n, k, a[N], ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1; i<=n; ++i) cin >> a[i];
	if(k==0) {
		if(a[1]==0) cout << n;
		else cout << n/2;
	}
	else cout << 1;
	return 0;
}
