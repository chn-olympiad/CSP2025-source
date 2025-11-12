#include <bits/stdc++.h>
using namespace std;
int f[4][100010];
int dp[210][210][210];
int n;
bool cmp(int x, int y) {
	return x > y;
}
void ans() {
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &f[1][i], &f[2][i], &f[3][i]);
	}
	int maxn = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			for(int k = 0; k <= i - j; k++) {
				dp[i][j][k] = 0;
				if(i - j - k > 0) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + f[3][i]);
				}
				if(j > 0) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + f[1][i]);	
				} 
				if(k > 0) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + f[2][i]);
				}
				//cout << dp[i][j][k] << " \t";
			}
			//cout << endl;
		}
		//cout << endl;
	}
	int rec[4];
	for(int j = 0; j <= n; j++) {
		for(int k = 0; k <= n - j; k++) {
			if(j > n / 2 || k > n / 2 || (n - j - k) > n / 2) {
				continue;
			}
			if(dp[n][j][k] > maxn) {
				rec[1] = j, rec[2] = k, rec[3] = n - j - k;
			}
			maxn = max(maxn, dp[n][j][k]);
		}
	}
	printf("%d\n", maxn);
	return;
}
void pian() {
	int ok2 = 1, ok3 = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &f[1][i], &f[2][i], &f[3][i]);
		ok2 = ok2 && (f[2][i] == 0);
		ok3 = ok3 && (f[3][i] == 0);
	}
	if(ok3) {
		if(ok2) {
			sort(f[1] + 1, f[1] + 1 + n, cmp);
			int sum = 0;
			for(int i = 1; i <= n / 2; i++) {
				sum += f[1][i];
			}
			printf("%d\n", sum);
			return;
		} else {
			vector<int> k1, k2;
			int sum = 0;
			for(int i = 1; i <= n; i++) {
				sum += max(f[1][i], f[2][i]);
				if(f[2][i] > f[1][i]) {
					k2.push_back(f[2][i] - f[1][i]);
				} else {
					k1.push_back(f[1][i] - f[2][i]);
				}
			}
			if(k1.size() > k2.size()) {
				int c = k1.size() - k2.size();
				c >> 1;
				sort(k1.begin(), k1.end());
				for(int i = 0; i < c; i++) {
					sum -= k1[i];
				}
			} 
			if(k2.size() > k1.size()) {
				int c = k2.size() - k1.size();
				c >> 1;
				sort(k2.begin(), k2.end());
				for(int i = 0; i < c; i++) {
					sum -= k2[i];
				}
			} 
			printf("%d\n", sum);
			return;
		}
	} else {
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			sum += max(f[3][i], max(f[1][i], f[2][i]));
		}
		printf("%d\n", sum);
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		scanf("%d", &n);
		if(n <= 200) ans();
		else pian();
	}
	return 0;
}
