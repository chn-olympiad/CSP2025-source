#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long LL;
const int N = 510;
const int Mod = 998244353;

namespace problem {

int n, m;
LL f[20][(1 << 18)][20];
std::string s;
int c[N];
int mp[(int)2e6 + 10];
int lowbit(int x) {
	return x & (-x);
}
void qm(LL &x) {
	if (x >= Mod)
		x %= Mod;
}
void dfs(int now, int num, int k, int nk, int i) {
	if (now == n + 1) {
		//std::cout << i << " " << num << "\n";
		for (int x = num; x; x -= lowbit(x)) {
			int j = mp[lowbit(x)] + 1;
			for (int k = 0; k < i; k++) {
				if (k >= c[j] || s[i] == '0') {
					f[i][num][k + 1] += f[i - 1][num - lowbit(x)][k];
					//std::cout << i << " " << num << " " << k + 1 << " " << f[i][num][k + 1] << " " << f[i - 1][num - lowbit(x)][k] << "\n";
					qm(f[i][num][k + 1]);
				} else {
					f[i][num][k] += f[i - 1][num - lowbit(x)][k];
					//std::cout << i << " " << num << " " << k << " " << f[i][num][k] << " " << f[i - 1][num - lowbit(x)][k] << "\n";
					qm(f[i][num][k]);
				}
			}
		}
		return ;
	}
	if (nk < k)
		dfs(now + 1, num * 2 + 1, k, nk + 1, i);
	if (n - now + 1 + nk > k)
		dfs(now + 1, num * 2, k, nk, i);
}
void sol1() {
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dfs(1, 0, i, 0, i);
	}
	LL ans = 0;
	for (int i = 0; i <= n - m; i++) {
		ans = (ans + f[n][(1 << n) - 1][i]) % Mod;
		//std::cerr << f[n][(1 << n) - 1][i] << " ";
	}
	std::cout << ans;
}
void solve() {
	for (int i = 0; i <= 20; i++) {
		mp[(1 << i)] = i;
	}
	std::cin >> n >> m;
	std::cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}
	if (n <= 18) {
		sol1();
	}
}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	problem::solve();
	return 0;
}