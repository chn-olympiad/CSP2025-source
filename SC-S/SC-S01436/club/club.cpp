#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>; 

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
const int N = 3 + 1e5;

int n;
array<int, 3> a[N];

int dp[102][102];

void case_n_less_200() {
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = min(i, n / 2); j >= 0; --j) {
			for (int k = min(i, n / 2); k >= 0; --k) {
				dp[j][k] = dp[j][k] + a[i][2];
				if (j >= 1) {
					dp[j][k] = max(dp[j][k], dp[j - 1][k] + a[i][0]);
				}
				if (k >= 1) {
					dp[j][k] = max(dp[j][k], dp[j][k - 1] + a[i][1]);
				}
//				if (i - j - k >= 0 && i - j - k <= n / 2) {
//					cout << n - j - k << " " << j << " " << k << "    " << dp[j][k] << endl;
//				}
			}
		}
//		cout << endl;
	}
	
	int ans = 0;
	for (int j = 0; j <= n / 2; ++j) {
		for (int k = 0; k <= n / 2 && j + k <= n; ++k) {
			int q = n - j - k;
			if (q > n / 2) {
				continue;
			}
//			cout << q << ' ' << j << "   " << k << " ------- " << dp[j][k] << endl;
			ans = max(ans, dp[j][k]);
			
		}
	}
	cout << ans << endl;
	
}

void case_A() {
	sort(a + 1, a + n + 1, [&](array<int, 3> &x, array<int, 3> &y) {
		return x[1] > y[1];
	});
	int ans = 0;
	for (int i = 1; i <= n / 2; ++i) {
		ans += a[i][0];
	}
	cout << ans << endl;
}

void case_B() {
	
//	-x + y
	sort(a + 1, a + n + 1, [&](array<int, 3> &x, array<int, 3> &y) {
		return -x[0] + x[1] > -y[0] + y[1];
	});
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += a[i][0];
	}
	for (int i = 1; i <= n / 2; ++i) {
		ans += -a[i][0] + a[i][1];
	}
	cout << ans << endl;
}

void case_rd() {
	sort(a + 1, a + n + 1, [&](array<int, 3> &x, array<int, 3> &y) {
		return max({x[0], x[1], x[2]}) > max({y[0], y[1], y[2]});
	});
	int ans = 0;
	
	int cnt[3] = {};
	
	vector<int> p = {0, 1, 2};
	
	for (int i = 1; i <= n; ++i) {
		sort(p.begin(), p.end(), [&](int x, int y) {
			return a[i][x] > a[i][y];
		});
		for (auto j : p) {
			if (cnt[j] >= n / 2) {
				continue;
			}
			++cnt[j];
			ans += a[i][j];
		}
	}
	
	cout << ans << endl;
	
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}
	
	if (n <= 200) {
		case_n_less_200();
		return;
	}
	
	int all0_1 = 1, all0_2 = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i][1]) {
			all0_1 = 0;
		}
		if (a[i][2]) {
			all0_1 = 0;
		}
	}
	
	if (all0_1 && all0_2) {
		case_A();
		return ;
	}
	if (all0_2) {
		case_B();
		return ;
	}
	
	case_rd();
	
}

int main() {
//	freopen("D:\\work\\club1.in", "r", stdin);
//	freopen("D:\\work\\club\\club1.in", "r", stdin);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}