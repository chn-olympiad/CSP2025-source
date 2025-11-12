#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(!isdigit(c)) {
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
} 
const int N = 1e5 + 5;
int T, n, a[N][3], bot[3], ans, b[N];
int dp[205][205][205];
void dfs(int now, int cnt) {
	if(now > n) {
		ans = max(ans, cnt);
		return ;
	}
	for(int i = 0; i < 3; ++i) {
		if(bot[i] < n / 2) {
			bot[i]++;
			dfs(now + 1, cnt + a[now][i]);
			bot[i]--;
		}
	}
}
void solve() {
	int tmp = 0;
	ans = 0;
	n = read();
	for(int i = 1; i <= n; ++i)
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read(), tmp += a[i][1] + a[i][2];
	if(n <= 10) {
		dfs(1, 0);
		cout << ans << '\n';
		return ;
	}
	if(n <= 200) {
		memset(dp, -1, sizeof(dp));
		dp[0][0][0] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j <= n / 2; ++j) {
				for(int k = 0; k <= n / 2; ++k) {
					if(j > 0 && dp[i - 1][j - 1][k] != -1) 
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][0]);
					if(k > 0 && dp[i - 1][j][k - 1] != -1) 
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][1]);
					if(i - j - k <= n / 2 && dp[i - 1][j][k] != -1) 
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][2]); 
				}
			}
		}
		for(int i = 0; i <= n / 2; ++i) {
			for(int j = 0; j <= n / 2; ++j)
				if(n - i - j <= n / 2 && i <= n / 2 && j <= n / 2) ans = max(ans, dp[n][i][j]);
		}
		cout << ans << '\n';
	}
	if(tmp == 0) {
		for(int i = 1; i <= n; ++i)
			b[i] = a[i][0];
		sort(b + 1, b + n + 1);
		for(int i = n; i >= n / 2 + 1; --i)
			ans += b[i];
		cout << ans << '\n';
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T--)
		solve();
	return 0;
}
