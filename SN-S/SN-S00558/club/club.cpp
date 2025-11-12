#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;

using tup = tuple<int, int, int>;

const int N = 101000;
int n;
ll a[N][3], dp[N][3];
tup x[N][3];

inline void solve() {
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%lld", &a[i][j]), dp[i][j] = 0; 
	x[1][0] = {1, 0, 0}, x[1][1] = {0, 1, 0}, x[1][2] = {0, 0, 1};
	dp[1][0] = a[1][0], dp[1][1] = a[1][1], dp[1][2] = a[1][2];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 3; j++) {
			int l0 = get<0>(x[i][j]), l1 = get<1>(x[i][j]), l2 = get<2>(x[i][j]);
			if (l0 < n / 2) {
				if (dp[i + 1][0] < dp[i][j] + a[i + 1][0]) {
					dp[i + 1][0] = dp[i][j] + a[i + 1][0];
					x[i + 1][0] = {l0 + 1, l1, l2};
				}
			}
			if (l1 < n / 2) {
				if (dp[i + 1][1] < dp[i][j] + a[i + 1][1]) {
					dp[i + 1][1] = dp[i][j] + a[i + 1][1];
					x[i + 1][1] = {l0, l1 + 1, l2};
				}
			}
			if (l2 < n / 2) {
				if (dp[i + 1][2] < dp[i][j] + a[i + 1][2]) {
					dp[i + 1][2] = dp[i][j] + a[i + 1][2];
					x[i + 1][2] = {l0, l1, l2 + 1};
				}
			}
		}
	printf("%lld\n", max({dp[n][0], dp[n][1], dp[n][2]}));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
