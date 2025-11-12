#include <bits/stdc++.h>
using namespace std;
#define nit long long
const nit N = 5e5 + 100;
nit n, k, a[N], b[N], dp[N];
map<nit, nit> lst;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	for(nit i = 1; i <= n; i ++) cin >> a[i], b[i] = b[i - 1] ^ a[i];
	
	for(nit i = 1; i <= n; i ++) {
		if(lst[b[i] ^ k] == 0) {
			if((b[i] ^ k) == 0) dp[i] = max(dp[0] + 1, dp[i - 1]);
			else dp[i] = dp[i - 1];
		}
		else dp[i] = max(dp[i - 1], dp[lst[b[i] ^ k]] + 1);
		
		lst[b[i]] = i;
		
//		cout << dp[i] << ' ';
	}
	cout << dp[n];
	return 0;
}
