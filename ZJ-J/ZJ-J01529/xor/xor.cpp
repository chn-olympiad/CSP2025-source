#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N], dp[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 0; i <= n; i++){
		int cnt = 0;
		for(int j = i + 1; j <= n; j++){
			cnt ^= a[j];
			dp[j] = max(dp[j],dp[j - 1] );
			if(cnt == k) {
				dp[j] = max(dp[i] + 1, dp[j]);
				break;
			}
		}
	}
	cout << dp[n];
	return 0;
}
/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
