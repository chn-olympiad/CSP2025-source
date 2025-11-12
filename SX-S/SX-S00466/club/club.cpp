#include <bits/stdc++.h>
using namespace std;
int n, t, maxx;
//dp[i][j] 第i个人去第j个部门能获得的最大值；
//int dp[100010][5];

int a[100010][5], cnt[5], ans, aa [100010], bb[100010];
struct Node{
	int cha;
}c[100010];

//void dfs(int x,int y,int ans){
//	ans+=a[x][y];
//	if(x==n){
//		ans-=a[x][y];
//		return ;
//	}
//	for(int i=1;i<=3;i++){
//		if(cnt[i]<maxx){
//			cnt[i]++;
//			dfs(x+1,i,ans);
//			cnt[i]--;
//		}
//	}
//}
bool cmp(Node x1,Node x2){
	return x1.cha<x2.cha;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		maxx = n / 2;
		bool flag2 = true;
		bool flag3 = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			c.cha=abs(a[i][1]-a[i][2]);
			aa[i] = a[i][1];
			if (a[i][3] != 0)
				flag3 = false;
			if (a[i][2] != 0)
				flag2 = false;
		}
		if (flag3 == true) {
			if (flag2 == true) {
				sort(aa + 1, aa + 1 + n, greater<int>() );
				for (int i = 1; i <= maxx; i++) {
					ans += a[i][1];
				}
				cout << ans << endl;
			} 
		}
		if (n == 2) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (i != j) {
						ans = max(ans, a[1][i] + a[2][j]);
					}
				}
			}
			cout << ans << endl;
		}
		if (n == 4) {
			for (int i = 1; i <= 3; i++) {
				cnt[i]++;
				for (int j = 1; j <= 3; j++) {
					cnt[j]++;
					for (int k = 1; k <= 3; k++) {
						cnt[k]++;
						for (int z = 1; z <= 3; z++) {
							cnt[z]++;
							if (cnt[1] == 2 || cnt[2] == 2 || cnt[3] == 2 || cnt[4] == 2 || (cnt[1] == 1 && cnt[2] == 1 && cnt[3] == 1)) {
								ans = max(ans, a[1][i] + a[2][j] + a[3][k] + a[4][z]);
							}
							cnt[z]--;

						}
						cnt[k]--;
					}
					cnt[j]--;
				}
				cnt[i]--;
			}
			cout << ans << endl;
		}
	}
//		memset(dp, 0, sizeof(dp));
//		dp[1][1] = a[1].m1;
//		dp[1][2] = a[1].m2;
//		dp[1][3] = a[1].m3;
//		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
//		for (int i = 1; i <= n; i++) {
//			if (dp[i - 1][1] > dp[i - 1][2] && dp[i - 1][1] > dp[i - 1][3]) {
//				if (cnt1 != maxx) {
//					cnt1++;
//					dp[i][1] = dp[i - 1][1] + a[i].m1;
//					dp[i][2] = dp[i - 1][1] + a[i].m2;
//					dp[i][3] = dp[i - 1][1] + a[i].m3;
//				} else if (dp[i - 1][2] > dp[i - 1][3]) {
//					cnt2++;
//					dp[i][1] = dp[i - 1][2] + a[i].m1;
//					dp[i][2] = dp[i - 1][2] + a[i].m2;
//					dp[i][3] = dp[i - 1][2] + a[i].m3;
//				} else {
//					cnt3++;
//					dp[i][1] = dp[i - 1][3] + a[i].m1;
//					dp[i][2] = dp[i - 1][3] + a[i].m2;
//					dp[i][3] = dp[i - 1][3] + a[i].m3;
//				}
//
//			} else if (dp[i - 1][2] > dp[i - 1][1] && dp[i - 1][2] > dp[i - 1][3]) {
//				if (cnt2 != maxx) {
//					cnt2++;
//					dp[i][1] = dp[i - 1][2] + a[i].m1;
//					dp[i][2] = dp[i - 1][2] + a[i].m2;
//					dp[i][3] = dp[i - 1][2] + a[i].m3;
//				} else if (dp[i - 1][3] > dp[i - 1][1]) {
//					cnt3++;
//					dp[i][1] = dp[i - 1][3] + a[i].m1;
//					dp[i][2] = dp[i - 1][3] + a[i].m2;
//					dp[i][3] = dp[i - 1][3] + a[i].m3;
//				} else {
//					cnt1++;
//					dp[i][1] = dp[i - 1][1] + a[i].m1;
//					dp[i][2] = dp[i - 1][1] + a[i].m2;
//					dp[i][3] = dp[i - 1][1] + a[i].m3;
//				}
//
//			} else if (dp[i - 1][3] > dp[i - 1][1] && dp[i - 1][3] > dp[i - 1][2]) {
//				if (cnt3 != maxx) {
//					cnt3++;
//					dp[i][1] = dp[i - 1][3] + a[i].m1;
//					dp[i][2] = dp[i - 1][3] + a[i].m2;
//					dp[i][3] = dp[i - 1][3] + a[i].m3;
//				} else if (dp[i - 1][2] > dp[i - 1][1]) {
//					cnt2++;
//					dp[i][1] = dp[i - 1][2] + a[i].m1;
//					dp[i][2] = dp[i - 1][2] + a[i].m2;
//					dp[i][3] = dp[i - 1][2] + a[i].m3;
//				} else {
//					cnt1++;
//					dp[i][1] = dp[i - 1][1] + a[i].m1;
//					dp[i][2] = dp[i - 1][1] + a[i].m2;
//					dp[i][3] = dp[i - 1][1] + a[i].m3;
//				}
//			}
//		}
//		printf("%d\n", max(dp[n][1], max(dp[n][2], dp[n][3])));
//	}
	return 0;
}