#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[100000];
const int mod = 998244353;
long long ans = 0;
int vis[100000];
int h[100000];
int f[100000];

int dfs(int x, long long sum, int maxn, int cnt) {

	if (x > n) {
		bool flag = 1;
		if (cnt < 3) {
			flag = 0;
		} else {
			if (sum <= maxn * 2) {
				flag = 0;
			}
		}
		if (flag) {
			ans++;
			ans %= mod;
		}
		return f[x] = ans;
	}
	if (f[x] != 0) {
		return f[x];
	}
	h[x] = 0;
	dfs(x + 1, sum, maxn, cnt);
	h[x] = 1;
	maxn = max(maxn, a[x]);
	dfs(x + 1, sum + a[x], maxn, cnt + 1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << dfs(1, 0, 0, 0);
}