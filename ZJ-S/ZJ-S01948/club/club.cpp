#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
const int maxn = 200;
const int maxm = 1e5 + 5;
int t, n;
int a[4][maxm], dp[2][maxn][maxn];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	// freopen("club.in", "r", stdin);
	// freopen("club.out", "w", stdout);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		cin >> n;
		int max1 = 0, max2 = 0;
		REP(i, 1, n){
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			max1 = max(a[2][i], max1);
			max2 = max(a[3][i], max2);
		}
		int ans = 0;
		if (max1 == 0 && max2 == 0){
			sort(a[1] + 1, a[1] + n + 1, cmp);
			REP(i, 1, n / 2){
				ans += a[1][i];
			}
		}
		else{
			REP(j, 0, n / 2){
				REP(k, 0, n / 2){
					dp[0][j][k] = dp[1][j][k] = 0;
				}
			}
			REP(i, 1, n){
				REP(j, 0, min(i, n / 2)){
					REP(k, 0, min(i, n / 2)){
						if (i - j - k > n / 2 || j + k > i){
							continue;
						}
						dp[i & 1][j][k] = 0;
						if (j > 0){
							dp[i & 1][j][k] = max(dp[(i & 1) ^ 1][j - 1][k] + a[1][i], dp[i & 1][j][k]);
						}
						if (k > 0){
							dp[i & 1][j][k] = max(dp[(i & 1) ^ 1][j][k - 1] + a[2][i], dp[i & 1][j][k]);
						}
						if (i - j - k > 0){
							dp[i & 1][j][k] = max(dp[(i & 1) ^ 1][j][k] + a[3][i], dp[i & 1][j][k]);
						}
						ans = max(ans, dp[i & 1][j][k]);
					}
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
