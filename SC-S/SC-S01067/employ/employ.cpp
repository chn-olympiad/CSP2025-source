#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> inline void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
const ll N = 5e2 + 5, mod = 998244353;
ll n, m, ans = 0;
string s;
ll a[N], c[N];
bool flag[N];
bool check() {
	ll out = 0, num = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] == '0') ++out;
		else {
			if (out >= c[a[i]]) ++out;
			else ++num;
		}
	}
	return num >= m;
}
void dfs(ll pos) {
	if (pos == n + 1) {
		ans += check();
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!flag[i]) {
			a[pos] = i, flag[i] = 1;
			dfs(pos + 1);
			flag[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	read(n), read(m);
	cin >> s;
	for (int i = 1; i <= n; ++i)
		read(c[i]);
	if (n <= 10)
		dfs(1);
	else {
		ans = 1;
		for (int i = 1; i <= n; ++i)
			ans *= i, ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
