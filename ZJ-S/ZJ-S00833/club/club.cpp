#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t, n, mx;
struct node {
	int b[4];
}a[100010];
int ans;
void dfs(int p, int cnt1, int cnt2, int cnt3, int sum) {
	if(p > n) {
		ans = max(ans, sum);
		return;
	}
	if(cnt1 < mx) dfs(p + 1, cnt1 + 1, cnt2, cnt3, sum + a[p].b[1]);
	if(cnt2 < mx) dfs(p + 1, cnt1, cnt2 + 1, cnt3, sum + a[p].b[2]);
	if(cnt3 < mx) dfs(p + 1, cnt1, cnt2, cnt3 + 1, sum + a[p].b[3]);
}
bool cmp1(node x, node y) {
	if(x.b[1] != y.b[1]) return x.b[1] > y.b[1];
	else if(x.b[2] != y.b[2]) return x.b[2] > y.b[2];
	else return x.b[3] > y.b[3];
}
bool cmp2(node x, node y) {
	if(x.b[2] != y.b[2]) return x.b[2] > y.b[2];
	else return x.b[1] > y.b[1];
}
int dp[210][210][210];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t --) {
		cin >> n; mx = n / 2;
		for(int i = 1; i <= n; i ++) cin >> a[i].b[1] >> a[i].b[2] >> a[i].b[3];
		ans = 0;
		if(n <= 10) { 
			dfs(1, 0, 0, 0, 0);
			cout << ans << '\n';
			continue;
		}
		bool flag = 0;
		for(int i = 1; i <= n; i ++) {
			if(!(a[i].b[2] == a[i].b[3] && a[i].b[2] == 0)) flag = 1;
		}
		if(!flag) {
			sort(a + 1, a + n + 1, cmp1);
			int sum = 0;
			for(int i = 1; i <= mx; i ++) sum += a[i].b[1];
			continue;
		}
		flag = 0;
		for(int i = 1; i <= n; i ++)
			if(a[i].b[3] != 0) flag = 1;
		if(n == 100000 && flag) {
			sort(a + 1, a + n + 1, cmp1);
			int sum = 0;
			for(int i = 1; i <= n; i ++) {
				if(i <= mx) sum += a[i].b[1];
				else sum += a[i].b[2];
			}
			ans = max(ans, sum);
			sort(a + 1, a + n + 1, cmp2);
			sum = 0;
			for(int i = 1; i <= n; i ++) {
				if(i <= mx) sum += a[i].b[2];
				else sum += a[i].b[1];
			}
			ans = max(ans, sum);
			cout << ans << '\n';
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i ++) {
			for(int j = 0; j <= mx; j ++) {
				for(int k = 0; k <= mx && j + k <= i; k ++) {
					int l = i - j - k;
					if(l > mx) continue;
					if(l) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i].b[3]);
					if(j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i].b[1]);
					if(k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i].b[2]);
					if(i == n) ans = max(ans, dp[n][j][k]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//T-T