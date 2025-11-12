#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

struct Node {
	int i, x;
	bool can;
	bool operator<(const Node other) const {
		if (i != other.i) return i < other.i;
		if (x != other.x) return x < other.x;
		return can < other.can;
	}
};
const int N = 5e5 + 10;
int n, k, arr[N];
int ans;
map<Node, int> dp;

int dfs(int i, int x, bool can) {
	if (i > n) {
		if (!can)
			return 0;
		if (x == k)
			return 1;
		return 0;
	}
	
	Node node = {i, x, can};
	if (dp.count(node) != 0) {
		return dp[node];
	}

	int ret = 0, add = 0;
	if (x == k && can) {
		add = 1;
	}
	if (can) {
		ret = max(ret, dfs(i + 1, x ^arr[i], 1));  // 连上前面的
	}
	ret = max(ret, dfs(i + 1, 0, false) + add); // 不用
	ret = max(ret, dfs(i + 1, arr[i], true) + add); // 新开

	dp[node] = ret;
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	ans = dfs(1, 0, 0);
	cout << ans << endl;

	return 0;
}

// dfs版本能拿55~70分
