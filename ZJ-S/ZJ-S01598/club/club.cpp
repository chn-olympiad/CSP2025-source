#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;

typedef pair<int,int> PII;
int t,n;
priority_queue<PII,vector<PII>,greater<PII>> q[N][4][4];
int dp[N][4], c[N][4];

int solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> c[i][1] >> c[i][2] >> c[i][3];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++){
			dp[i][j] = -INT_MAX;
			for(int k = 1;k <= 3;k++) while(q[i][j][k].size()) q[i][j][k].pop();
			for(int k = 1;k <= 3;k++){
				int maxs = 0, la = 0;
				if(q[i-1][k][j].size()) for(int x = 1;x <= 3;x++) if(c[q[i-1][k][j].top().second][x] != q[i-1][k][j].top().first) maxs = max(maxs, c[q[i-1][k][j].top().second][x]), la = x;
				if(la and q[i-1][k][j].size() and dp[i-1][k] - q[i-1][k][j].top().first + maxs + c[i][j] > dp[i][j]){
					dp[i][j] = dp[i-1][k] - q[i-1][k][j].top().first + maxs + c[i][j];
					q[i][j][1] = q[i-1][k][1];
					q[i][j][2] = q[i-1][k][2];
					q[i][j][3] = q[i-1][k][3];
					q[i][j][j].pop();
					q[i][j][la].push({maxs, la});
					q[i][j][j].push({c[i][j], i});
				}
				if(q[i-1][k][j].size() < n/2 and dp[i-1][k] + c[i][j] > dp[i][j]){
					dp[i][j] = dp[i-1][k] + c[i][j];
					q[i][j][1] = q[i-1][k][1];
					q[i][j][2] = q[i-1][k][2];
					q[i][j][3] = q[i-1][k][3];
					q[i][j][j].push({c[i][j], i});
				}
			}
		}
	}
	return max(dp[n][1], max(dp[n][2], dp[n][3]));
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) cout << solve() << endl;
	return 0;
}
