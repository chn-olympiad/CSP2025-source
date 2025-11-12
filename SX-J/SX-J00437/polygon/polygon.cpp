#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

const int mod = 998244353;
const int N = 5020;
int n, arr[N];
int ans, fac[N];

int qpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
int dfs(int i, int sm, int mx, int count) {
	if (i > n) {
		if (sm > mx * 2 && count >= 3) return 1;
		return 0;
	}
	
	int ret = 0;
	ret = (ret + dfs(i + 1, sm + arr[i], max(mx, arr[i]), count+1)) % mod;
	ret = (ret + dfs(i + 1, sm, mx, count)) % mod;
	
	return ret;
}
int C(int n, int m) {
	if (n == m) return 1;
	return fac[n] * qpow(fac[n-m] * fac[m], mod-2) % mod;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n; bool type = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] != 1)
			type = 0;
	}
	fac[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fac[i] = fac[i - 1] * i;
	}
	if (type) {
		if (n == 3) {
			cout << 1 << endl;
			return 0;
		}
		ans = 0;
		for (int i = 3; i <= n; ++i)
			ans = (ans + C(n, i)) % mod;
		cout << ans << endl;
		return 0;
	}
	ans = dfs(1, 0, 0, 0);
	cout << ans << endl;
	
	return 0;
}

// 暴力：40分

/* 电脑很快
1e9 ~= 0.368s
*/