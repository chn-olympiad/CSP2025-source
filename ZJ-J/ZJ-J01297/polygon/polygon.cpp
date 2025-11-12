#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n;
vector<int> a;

int solve1() {
	int maxn = max(a[0], max(a[1], a[2]));
	int sum = a[0] + a[1] + a[2];
	return maxn * 2 < sum;
}

void dfs(int sum, int maxn, int x, int y, bool flag, int &cnt) {
	if (maxn * 2 < sum && y >= 3 && flag) {
		cnt++;
		if (cnt == mod) cnt = 0;
	}
	if (x == n) return;
	dfs(sum + a[x], max(maxn, a[x]), x+1, y+1, 1, cnt);
	dfs(sum, maxn, x+1, y, 0, cnt);
}
int solve2() {
	int cnt = 0;
	dfs(0, 0, 0, 0, 0, cnt);
	return cnt;
}

int sqr(int n) { return n * n % mod; }
int pow2(int n) {
	if (n == 0) return 1;
	else if (n == 1) return 2;
	else return sqr(pow2(n / 2)) * (n % 2 == 1 ? 2 : 1) % mod;
}
int solve3() {
	return (pow2(n) - n - 1 - n * (n-1) / 2) % 998244353;
}

int solve() {
	if (n == 3) return solve1();
	else if (n <= 20) return solve2();
	else {
		bool flag = true;
		for (int i = 0;i < n;i++) if (a[i] != 1) flag = false;
		if (flag) return solve3();
		else return solve2();
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	a.resize(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	cout << solve();
	return 0;
}
