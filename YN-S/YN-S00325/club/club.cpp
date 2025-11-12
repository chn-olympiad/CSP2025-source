#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

inline int read() {
	int num = 0, sign = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		sign = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch && ch <= '9')
		num = (num << 1) + (num << 3) + ch - '0', ch = getchar();
	return sign < 0 ? -num : num;
}
const int MAXN = 1e5 + 8;
const ll NINF = 0xc0c0c0c0c0c0c0c0;

struct node {
	ll a, b, c;
} memb[MAXN];
int n;
ll dp[2][3][MAXN];

int main() {
	freopen("club", "r", stdin);
	freopen("club", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++)
			memb[i].a = read(), memb[i].b = read(), memb[i].c = read();
		memset(dp, NINF, sizeof(dp));
		dp[1][0][1] = memb[1].a, dp[1][1][1] = memb[1].b, dp[1][2][1] = memb[1].c;
		for (int i = 2; i <= n; i++) {
			for (int len = min(n / 2, i); len >= 1; len--) {
				dp[i % 2][0][len] = max(dp[(i + 1) % 2][0][len - 1] + memb[i].a,
				                        dp[(i + 1) % 2][0][len] + max(memb[i].b, memb[i].c));
				dp[i % 2][1][len] = max(dp[(i + 1) % 2][1][len - 1] + memb[i].b,
				                        dp[(i + 1) % 2][1][len] + max(memb[i].a, memb[i].c)),
				                    dp[i % 2][2][len] = max(dp[(i + 1) % 2][2][len - 1] + memb[i].c,
				                                        dp[(i + 1) % 2][2][len] + max(memb[i].a, memb[i].b));
			}
		}
		ll ans = 0;
		for (int len = 1; len <= n / 2; len++)
			ans = max({dp[n % 2][0][len], dp[n % 2][1][len], dp[n % 2][2][len]});
		cout << ans << "\n";
	}

	return 0;
}