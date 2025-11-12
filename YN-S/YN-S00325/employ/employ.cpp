#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

inline int read() {
	int num = 0, sign = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		sign = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch && ch <= '9')
		num = (num << 1) + (num << 3) + ch - '0', ch = getchar();
	return sign < 0 ? -num : num;
}
const int MAXN = 5e2 + 8;
const int MOD = 998244353;
int n, m, c[MAXN], a[MAXN], ans;
bool vis[MAXN];
string s;

bool check() {
	int res = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (cnt >= c[a[i + 1]] || s[i] == '0')
			cnt++;
		else
			res++;
	}
	return res >= m;
}

void dfs(int pos, int k) {
	if (k == n) {
		if (check())
			ans++, ans %= MOD;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			a[k + 1] = i;
			vis[i] = 1;
			dfs(i, k + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		a[1] = i;
		vis[i] = 1;
		dfs(i, 1);
		vis[i] = 0;
	}
	cout << ans;
	return 0;
}