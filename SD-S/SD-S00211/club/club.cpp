#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10001;
int T, S[N][4], num[4], ans, dp[N][3][N / 2];
bool vis[N];

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--){
		ans = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> S[i][1] >> S[i][2] >> S[i][3];
		}
		dp[1][1][0] = S[1][1], 
		dp[1][2][0] = S[1][2],
		dp[1][3][0] = S[1][3];
		for (int i = 2; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				int s = 0, len;
				for (int k = 0; k <= min(n / 2 - 1, i - 1); k++){
					for (int l = 1; l <= 3; l++){
						len = min(n / 2 - 1, i - 1);
//						cout << "len:" << len << endl;	
						for (int m = 0; m <= len; m++){
							if (k == 0 && l == j){
								continue; 
							}
							s = max (s, dp[i - 1][l][m]);
						}
					}
					dp[i][j][k] = s + S[i][j];
//					cout << i << " " << j << " " << k << endl;
//					cout << s << " " << S[i][j] << " " << dp[i][j][k] << endl << endl;
				}
			}
		}
		for (int i = 1; i <= 3; i++)
			ans = max(ans, dp[n][i][n / 2 - 1]);
		cout << ans << endl;
	} 
	
	return 0;
}
