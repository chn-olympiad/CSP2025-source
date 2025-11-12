#include <bits/stdc++.h> 
#define ll long long 
#define pii pair < int, int > 
#define fir first 
#define sec second 

using namespace std; 

const int N = 1e5 + 5; 

int T; 
int n; 
int a[N][4]; 
int dp[2][2005][2005]; 
int nid, pid; 
int ans; 

signed main() {
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
	
	scanf("%d", &T); 
	while (T--) {
		scanf("%d", &n); 
		for (int i = 1; i <= n; i++) 
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]); 
		ans = 0; 
		for (int i = 1; i <= n; i++) {
			nid = i & 1; 
			pid = nid ^ 1; 
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k + j <= i; k++) {
					dp[nid][j][k] = 0; 
					if (j) 
						dp[nid][j][k] = max(dp[nid][j][k], dp[pid][j - 1][k] + a[i][1]); 
					if (k) 
						dp[nid][j][k] = max(dp[nid][j][k], dp[pid][j][k - 1] + a[i][2]); 
					if (j + k + 1 <= i) dp[nid][j][k] = max(dp[nid][j][k], dp[pid][j][k] + a[i][3]); 
//					ans = max(ans, dp[nid][j][k]); 
				}
			}
		}
		for (int j = 0; j <= n / 2; j++) 
			for (int k = 0; k <= n / 2 && j + k <= n; k++) {
				if (n - j - k <= n / 2) ans = max(ans, dp[n & 1][j][k]); 
			}
		for (int j = 0; j <= n; j++) for (int k = 0; k + j <= n; k++) dp[0][j][k] = dp[1][j][k] = 0; 
		printf("%d\n", ans); 
	}
	
	return 0; 
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1


*/
/*
1
10
6839 5455 15586     1
11767 12919 2643    2
13775 8904 19938    3
13717 11997 15170   1
13707 2404 17497    3
3471 2462 8073      3
18467 14346 18663   3
13582 4839 15785    3
11875 7476 12308    3
8568 3134 18522     3

*/