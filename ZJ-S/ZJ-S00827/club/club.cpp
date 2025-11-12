#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define inf 1e9
using ll = long long;
using db = double;
using namespace std;
constexpr int N = 1e5 + 5, M = 2e2 + 5, P = 1e9 + 7;
int T, n, stk[N], stk1[N], ans;
struct node {
	int a, b, c, id;
} a[N], b[N];
int dp[M][M][M];
bool B = true;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	for (cin >> T; T; -- T, ans = 0) {
		cin >> n;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i].a >> a[i].b >> a[i].c, a[i].id = i;
			if (a[i].c) B = false;
			b[i] = a[i];
		}
		if (n < M) {
			memset(dp, 0, sizeof dp);
			for (int i = 1; i <= n; ++ i)
				for (int j = 0; j <= min(i, n / 2); ++ j) {
					for (int k = 0; k <= n / 2 && j + k <= i; ++ k) {
						int l = i - j - k;
						if (l > n / 2) continue;
						if (j) dp[i][j][k] = dp[i - 1][j - 1][k] + a[i].a;
						if (k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i].b);
						if (l) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i].c);
						ans = max(ans, dp[i][j][k]);
					}
				}
			cout << ans << '\n';
		}
		else if (B) {
			sort(a + 1, a + n + 1, [](node x, node y) {
				return x.a > y.a;
			});
			for (int i = 1; i <= n / 2; ++ i) stk[i] = a[i].id, ans += b[a[i].id].a;
			for (int i = n / 2 + 1; i <= n; ++ i) stk1[i - n / 2] = a[i].id, ans += b[a[i].id].b;
			sort(stk + 1, stk + n / 2 + 1, [](int x, int y) {
				return b[x].a - b[x].b < b[y].a - b[y].b;
			});
			sort(stk1 + 1, stk1 + n / 2 + 1, [](int x, int y) {
				return b[x].a - b[x].b > b[y].a - b[y].b;
			});
			for (int i = 1, j = 1; i <= n / 2; ++ i, ++ j) {
				if (b[stk[i]].a - b[stk[i]].b >= b[stk1[j]].a - b[stk1[j]].b) break;
				ans = ans - b[stk[i]].a - b[stk1[j]].b + b[stk[i]].b + b[stk1[j]].a;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}