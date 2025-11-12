#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e5 + 10;

long long ar[maxn][4], n;
long long ans = 0;
void dfs(long long i, long long sum, long long a, long long b, long long c) {
	if (a + b + c == n) {
		ans = max(ans, sum);
		return ;
	}
	if (a < n / 2) {
		long long v = ar[i][0]; 
		dfs(i + 1, (sum + v), a + 1, b, c);
	}
	if (b < n / 2) {
		long long v = ar[i][1];
		dfs(i + 1, (sum + v), a, b + 1, c);
	}
	if (c < n / 2) {
		long long v = ar[i][2];
		dfs(i + 1, (sum + v), a, b, c + 1);
	}
}

struct man{
	long long a1, b1, c1;
};

man v[maxn];

bool cmp(man a, man b) {
	return a.b1 > b.b1;
}

void solve() {
	for (long long i = 1; i <= n; i ++) {
		v[i].a1 = ar[i][0];
		v[i].b1 = ar[i][1];
		v[i].c1 = ar[i][2];
	}
	sort(v + 1, v + 1 + n, cmp);
	long long sum = 0;
	for (long long i = 1; i <= n / 2; i ++) {
		sum += v[i].b1;
	}
	cout << sum << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	long long T;
	cin >> T;
	while (T--) {
		cin >> n;
		bool tx1 = true;
		bool tx2 = true;
		for (long long i = 1; i <= n; i ++) {
			cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
			if (ar[i][0] != 0 || ar[i][2] != 0) {
				tx1 = false;
			}
		}
		if (tx1) {
			solve();
			continue;
		}
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	} 
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int dp[maxn][4];
int sy[maxn][4][4];
int a[maxn][4];
int main() {
	int T;
	cin >> T;
	while (T --) {
		int n;
		cin >> n;
		int tmp = n / 2;
		cout << tmp; 
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= n; i ++) {
			for (int j = 0; j < 3; j ++) {
				for (int k = 0; k < 3; k ++) {
					sy[i][j][k] = tmp;
				}
			}
		}

		for (int i = 1; i <= n; i ++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[0][2] = 0;
		for (int i = 1; i <= n; i ++) { // 第i个人 
			for (int j = 0; j < 3; j ++) { // 分配到第j个岗位 
				for (int k = 0; k < 3; k ++) { // 上一个人的岗位 
					if (dp[i - 1][k] + a[i][j] > dp[i][j]) {
						if (sy[i - 1][k][j] > 0) {
							dp[i][j] = dp[i - 1][k] + a[i][j];
							sy[i][j][0] = sy[i - 1][k][0];
							sy[i][j][1] = sy[i - 1][k][1];
							sy[i][j][2] = sy[i - 1][k][2];
							sy[i][j][j] --;
						}
					}
				}
				/*
				int v0 = dp[i - 1][0];
				int v1 = dp[i - 1][1];
				int v2 = dp[i - 1][2];
				
				if (sy[i - 1][j][0] > 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
					sy[i][j][0] = sy[i - 1][j][0] - 1;
				} 
				if (sy[i - 1][j][1] > 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
					sy[i][j][1] = sy[i - 1][j][1] - 1;
				} 
				if (sy[i - 1][j][2] > 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
					sy[i][j][2] = sy[i - 1][j][2] - 1;
				} 
				/*
				if (sy[i - 1][0] > 0 && sy[i - 1][0]) {
					dp[i][j] = max(dp[i][j], max(v0, max(v1, v2)) + a[i][j]);
					sy[i][j][j] = sy[i - 1][j] - 1;
				}
			}
		}
		/*
		for (int i = 0; i < 3; i ++) {
			for (int j = 1; j <= n; j ++) {
				cout << dp[j][i] << " ";
			}
			cout << endl;
		}
		cout << sy[1][3][0];
		cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << "\n";
	}
} 

/*
dp[i][j]:第i个人分配到第j位时最大价值
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1], dp
sy[i][j][k]:第i个人分配到j后岗位k所剩的数量 
*/

