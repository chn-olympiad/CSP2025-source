#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T, n, ans, cnt[5];
int dp[201][101][101];
bool vis[100001];
struct node{
	int t1, t2, t3;

}a[300001];
bool cmp(node d1, node d2){
	return d1.t1 > d2.t1;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--){
		ans = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		if (n > 200){		
			for (int i = 0; i < n; i++){
				for (int j = 1; j <= 3; j++){
					scanf("%d", &a[3 * i + j].t1);
					a[3 * i + j].t2 = j;
					a[3 * i + j].t3 = i + 1;
				}
			}
			sort(a + 1, a + 3 * n + 1, cmp);
			for (int i = 1; i <= 3 * n; i++){
				if (cnt[a[i].t2] == n / 2) continue;
				if (vis[a[i].t3]) continue;
				cnt[a[i].t2]++;
				vis[a[i].t3] = true;
				ans += a[i].t1;
			}
			printf("%d\n", ans);
		}else{
			for (int i = 0; i <= 200; i++){
				for (int j = 0; j <= 100; j++){
					for (int k = 0; k <= 100; k++) dp[i][j][k] = -200000005;
				}
			}
			dp[0][0][0] = 0;
			for (int i = 1; i <= n; i++){
				scanf("%d%d%d", &cnt[1], &cnt[2], &cnt[3]);
				for (int j = 0; j <= i; j++){
					for (int k = 0; k <= i; k++){
						if (j > n / 2 || k > n / 2) continue;
						if (i - j - k < 0 || i - j - k > n / 2) continue;
						if (j != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + cnt[1]);
						if (k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + cnt[2]);
						if (i - j - k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + cnt[3]);
						if (i == n) ans = max(dp[i][j][k], ans);
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
