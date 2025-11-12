#include <bits/stdc++.h>
using namespace std;
int n, m;

int solve1() {
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans %= 998244353;
	}
	return ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cout << solve1();
	return 0;
}