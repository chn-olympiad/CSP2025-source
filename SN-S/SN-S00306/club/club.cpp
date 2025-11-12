#include<bits/stdc++.h>
using namespace std;

struct Info{
	int a, b, c;
} a[100010];

int T, n, ans, dp[210][210][210];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				for(int k = 0; k <= n; k++){
					dp[i][j][k] = 0;
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= i; j++){
				for(int k = 0; k <= (i - j); k++){
					int l = i - j - k;
					if((j + 1) * 2 <= n){
						dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + a[i + 1].a);
					}
					if((k + 1) * 2 <= n){
						dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + a[i + 1].b);
					}
					if((l + 1) * 2 <= n){
						dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + a[i + 1].c);
					}
				}
			}
		}
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				int k = n - i - j;
				if((i * 2 <= n) && (j * 2 <= n) && (k * 2 <= n) && k >= 0){
					ans = max(ans, dp[n][i][j]);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
//awa
