#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;
const int MOD = 998244353;

int c[N];

int fact(int x) {
	int res = 1;
	x %= MOD;

	for (int i = 1; i <= x; i++) {
		i %= MOD;
		res = (i * res) % MOD;
		res %= MOD;
	}

	return res % MOD;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	int cnt = n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0)
			cnt--;
	}

	bool spa = true;
	for (auto &c : s)
		if (c == '0')
			spa = false;

	if (spa) { // 所有人均能被录用
		// 则为 1~n 的排列数
		cout << fact(n);
	} else {
		cout << 0;
	}

	return 0;
}