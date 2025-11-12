#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node{
	int a, b, c;
	int mx = 0;
}a[100010];
bool cmp (node a, node b) {
	return a.mx > b.mx;
}
int T, n;
int dp[N][5], s[N][5][5];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 1;i <= n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].mx = max(max(a[i].a, a[i].b), a[i].c);
		}
		int ans = 0, t = n / 2;
		sort(a + 1, a + n + 1, cmp);
		memset(s, 0, sizeof(s));
		memset(dp, 0, sizeof(dp));
		for (int i =1;i <= n;i++){ 
			for (int j = 1;j <= 3;j++){
				int ad = 0;
				if (s[i - 1][j][1] < t) {
					int cnt = dp[i][j];
					dp[i][j] = max(dp[i - 1][j], dp[i][j]);
					if (cnt != dp[i][j]) {
						s[i][j][1] = s[i - 1][1][1] + (j == 1?1:0);
						s[i][j][2] = s[i - 1][1][2] + (j == 2?1:0);
						s[i][j][3] = s[i - 1][1][3] + (j == 3?1:0);
					} 
				}
				if (s[i - 1][j][2] < t) {
					int cnt = dp[i][j];
					dp[i][j] = max(dp[i - 1][j], dp[i][j]);
					if (cnt != dp[i][j]) {
						s[i][j][1] = s[i - 1][2][1] + (j == 1?1:0);
						s[i][j][2] = s[i - 1][2][2] + (j == 2?1:0);
						s[i][j][3] = s[i - 1][2][3] + (j == 3?1:0);
					} 
				}
				if (s[i - 1][j][3] < t) {
					int cnt = dp[i][j];
					dp[i][j] = max(dp[i - 1][j], dp[i][j]);
					if (cnt != dp[i][j]) {
						s[i][j][1] = s[i - 1][3][1] + (j == 1?1:0);
						s[i][j][2] = s[i - 1][3][2] + (j == 2?1:0);
						s[i][j][3] = s[i - 1][3][3] + (j == 3?1:0);
					} 
				}
				if(j == 1)
					dp[i][j] += a[i].a;
				if(j == 2)
					dp[i][j] += a[i].b;
				if(j == 3)
					dp[i][j] += a[i].c;
			}
		}
		cout << max(dp[n][1], max(dp[n][2], dp[n][3]))<< "\n";
	}	
	return 0;
}

