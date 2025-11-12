#include <bits/stdc++.h>
using namespace std;
int my[100009][4];
long long ans = 0;
int n;

int dp[100009][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> my[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				for (int k = 1; k <= 3; k++) {
					dp[i][j] = max(dp[i - 1][k] + my[i][j], dp[i][j]);
				}
			}
		}
		ans = max(dp[n][1], max(dp[n][2], dp[n][3]));
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;

}
