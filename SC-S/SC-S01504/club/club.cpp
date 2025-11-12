#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int,3> ARR;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int N = 1e5 + 5;
int n,a[3][N];
namespace DP {
	const int N = 205;
	int dp[N][N][N];
	void gmax(int &a,int b) {
		if(b > a) a = b;
	}
	void solve() {
		int ans = 0;
		memset(dp,0xc0,sizeof dp);
		dp[0][0][0] = 0;
		for(int i = 0;i < n;i ++) {
			for(int j = 0;j <= n / 2 && j <= i;j ++) {
				for(int k = 0;k <= n / 2 && j + k <= i;k ++) {
					int l = i - j - k;
					if(l < 0 || l > i || l > n / 2) continue;
					gmax(dp[i + 1][j + 1][k]/* l */,dp[i][j][k] + a[0][i + 1]);
					gmax(dp[i + 1][j][k + 1]/* l */,dp[i][j][k] + a[1][i + 1]);
					gmax(dp[i + 1][j][k]/* l + 1 */,dp[i][j][k] + a[2][i + 1]);
				}
			}
		}
		for(int i = 0;i <= n / 2;i ++) {
			for(int j = 0;j <= n / 2;j ++) {
				int k = n - i - j;
				if(k < 0 || k > n / 2) continue;
				gmax(ans,dp[n][i][j]);
			}
		}
		cout << ans << "\n";
	}
}
namespace GD {
	bool vis[N];
	priority_queue<ARR> q;
	void solve() {
		int ans = 0;
		while(q.size()) q.pop();
		for(int i = 1;i <= n;i ++) {
			ans += a[0][i];
			if(a[1][i] == a[2][i]) {
				q.push({a[1][i] - a[0][i],0,i});
			}
			else {
				q.push({a[1][i] - a[0][i],1,i});
				q.push({a[2][i] - a[0][i],2,i});
			}
			vis[i] = 0;
		}
		int c[3] = {-n,0,0};
		for(int i = 1;i <= n / 2;) {
			int x = q.top()[0],y = q.top()[1],id = q.top()[2];
			q.pop();
			if(vis[id]) continue;
			ans += x,c[y] ++,vis[id] = 1,i ++;
		}
		while(q.size()) {
			int x = q.top()[0],y = q.top()[1],id = q.top()[2];
			q.pop();
			if(vis[id]) continue;
			if(x <= 0) break;
			if(c[y] < n / 2) {
				ans += x,c[y] ++,vis[id] = 1;
			}
		}
		cout << ans << "\n";
	}
}
void solve() {
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		for(int j = 0;j < 3;j ++) {
			cin >> a[j][i];
		}
	}
	if(n <= 200) DP::solve();
	else GD::solve();
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t = 1;
	cin >> t;
	while(t --) solve();
	return 0;
}