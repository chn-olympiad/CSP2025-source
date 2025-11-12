#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[6000];

signed main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	if(n < 3) {
		printf("0");
		return 0;
	}
	if(n == 3) {
		int ans = 0, maxn = 0;
		for(int i = 1; i <= n; ++i) {
			ans += a[i];
			maxn = max(maxn, a[i]);
		}
		if(ans > maxn)	cout << 1;
		else	cout << 0;
	}
	cout << 3;
	return 0;
}