//张巍邺-SN-J00223-西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N][3];
int dp[N][3];
int maxn[N][3];
int ton[3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	int n;
	cin >> T;
	while(T--) {
		memset(dp,0,sizeof dp);
		cin >> n;
		for(int i = 1; i<=n; i++) {
			for(int j = 1; j<=3; j++) {
				cin>>a[i][j];
			}

		}
		maxn[1][1] = a[1][1];
		for(int i = 1; i<=n; i++) {
			maxn[i][1] = max(maxn[i-1][1],a[i][1]);

		}


		for(int j = 1; j<=3; j++) {
			maxn[1][j] = max(maxn[1][j-1],a[1][j]);


		}
		for(int i = 2; i<=n; i++) {
			for(int j = 2; j<=3; j++) {
				maxn[i][j] = max(maxn[i-1][j],a[i][j]);
				maxn[i][j] = max(maxn[i][j-1],a[i][j]);
			}

		}
		for(int j = 1; j<=3; j++) {

			dp[1][j] = max(a[1][j],dp[1][j-1]);
//			dp[1][j] = max(dp[1][j],a[j][1]);
		}
		
		for(int i = 2; i<=n; i++) {
			for(int j = 1; j<=3; j++) {

				if(ton[j]<n/2) {
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]+maxn[i][j]);
					if(dp[i][j]==dp[i-1][j]+a[i][j]) {
						ton[j]++;
					}

				} else {
					dp[i][j] = max(dp[i-1][j],dp[i-2][j]+maxn[i][j]);
				}




			}
		}
		cout << dp[n][3]<<'\n';
	}
//	3
//	4
//	4 2 1
//	3 2 4
//	5 3 4
//	3 5 1
//	4
//	0 1 0
//	0 1 0
//	0 2 0
//	0 2 0
//	2
//	10 9 8
//	4 0 0

	return 0;
}
