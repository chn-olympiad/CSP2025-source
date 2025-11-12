#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e2 + 114, NN = 18 + 2, mod = 998244353;
int n, m;
char b[N];
int a[N];
void solve0() {
	for(int i = 0; i < n; ++i) cin >>a[i];
	static int p[N];
	for(int i = 0; i < n; ++i) p[i] = i;
	int ans = 0;
	do {
		int cnt = 0;
		for(int i = 0; i < n; ++i) if(b[i] == '0' || cnt >= a[p[i]]) ++cnt;
		if(n - cnt >= m) if(++ans == mod) ans = 0;
	} while(next_permutation(p, p + n));
	cout <<ans <<'\n';
}
int dp[NN][NN][1 << NN];
void smod(int &x) {
	while(x >= mod) x -= mod;
}
void solve1() {
	for(int i = 1; i <= n; ++i) cin >>a[i];
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; ++i) for(int j = 0; j <= i; ++j)
		for(int k = 0; k < (1 << n); ++k) for(int l = 0; l < n; ++l)
			if(k >> l & 1)
				smod(dp[i][j + (b[i - 1] == '0' || j >= a[l + 1])][k] += dp[i - 1][j][k ^ (1 << l)]);
	int ans = 0;
	for(int j = 0; j <= n - m; ++j) smod(ans += dp[n][j][(1 << n) - 1]);
	cout <<ans <<'\n';
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >>n >>m >>b;
	if(n > 10 && n <= 18) solve1();
	else solve0();
	return 0;
}
