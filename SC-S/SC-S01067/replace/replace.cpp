#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> inline void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
const ll N = 2e5 + 5, INF = 0;
ll n, q, bor[N], ans;
string s[N][2], t[2];
bool check(string s1, ll pos, ll num, string s2) {
	ll len = s1.size(), len2 = s[num][0].size();
	for (int i = pos; i < len; ++i) {
		if (i - pos + 1 > len2) break;
		if (s1[i] == s[num][0][i - pos]) s1[i] = s[num][1][i - pos];
		else return 0;
	}
	return s1 == s2;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(n), read(q);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; ++i) {
		if (n > 1000) {
			puts("0");
			continue;
		}
		ans = 0;
		cin >> t[0] >> t[1];
		ll len = t[0].size();
		for (int j = 1; j <= len; ++j) {
			for (int k = 1; k <= n; ++k) {
				ans += check(t[0], j - 1, k, t[1]);
			}
		}
		printf("%lld\n", ans);
	}
}
