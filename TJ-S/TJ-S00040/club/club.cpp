#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
long long dp[210][210][210], a[N], b[N], c[N];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(dp,0,sizeof dp);
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		if (n <= 200) {
			long long maxn = 0;
			for (int i = 0; i <= n/2; i++) {
				for (int j = 0; i+j <= n && j <= n/2; j++) {
					for (int k = 0; i+j+k <= n && k <= n/2; k++) {
						if (i > 0)
							dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k]);
						if (j > 0)
							dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]+b[i+j+k]);
						if (k > 0)
							dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]+c[i+j+k]);
						maxn = max(maxn,dp[i][j][k]);
					}
				}
			}
			cout << maxn << "\n";
		} else {
			sort(a+1,a+n+1,greater<int>());
			long long sum = 0;
			for (int i = 1; i <= n/2; i++) {
				sum += a[i];
			}
			cout << sum << "\n";
		}
	}
	return 0;
} 
