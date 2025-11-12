#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nMax = 201;
ll dp[nMax][nMax][nMax];
int a[nMax], b[nMax], c[nMax];

void solve(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	ll ans = 0;
	if(n > 300){
		sort(a + 1, a + n + 1);
		for(int i = n / 2 + 1; i <= n; i++) ans += a[i];
	}else{
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= i; j++){
				for(int k = 0; k <= (i - j); k++){
					dp[i][j][k] = 0;
					if(i - j - k > 0 && i - j - k <= n / 2) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + c[i]);
					if(j > 0 && j <= n / 2) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i]);
					if(k > 0 && k <= n / 2) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + b[i]);
					ans = max(ans, dp[i][j][k]);
//					printf("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
				}
			}
		}
	}
	printf("%lld\n", ans);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; scanf("%d", &t);
	for(int i = 0; i < t; i++) solve();
	return 0;
}
/*

*/
