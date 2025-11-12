#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define debug(x) cerr << #x << " = " << x << endl;
using namespace std;

struct Node {
	int a, b, c;
};
struct map_Node {
	int i;
	Node node;
	bool operator<(const map_Node other) const {
		if (i != other.i) return i < other.i;
		if (node.a != other.node.a) return node.a < other.node.a;
		if (node.b != other.node.b) return node.b < other.node.b;
		return node.c < other.node.c;
	}
};
const int N = 1e5 + 10;
int n, lim, a[N][4];
int ans, tet, cnt[4];
bool typeA, typeB, typeC, typeD;
map<map_Node, int> dp;

int dfs(int i, Node cont) {
	if (i > n) {
		return 0;
	}
	
	map_Node node = {i, cont};
	if (dp.count(node) != 0) {
		return dp[node];
	}
	
	int ret = 0;
	if (cont.a < lim) {
		Node ne = cont; ne.a++;
		ret = max(ret, dfs(i + 1, ne) + a[i][1]);
	}
	if (cont.b < lim) {
		Node ne = cont; ne.b++;
		ret = max(ret, dfs(i + 1, ne) + a[i][2]);
	}
	if (cont.c < lim) {
		Node ne = cont; ne.c++;
		ret = max(ret, dfs(i + 1, ne) + a[i][3]);
	}
	
	dp[node] = ret;
	return ret;
}

void solve() {
	dp.clear(); typeA = typeB = typeC = typeD = 1;
	cin >> n; lim = n / 2; ans = tet = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		
		if (a[i][2] != 0) typeA = 0;
		if (a[i][3] != 0) typeB = 0;
		
		int mx = max({
			a[i][1],
			a[i][2],
			a[i][3]
		}); tet += mx;
		if (mx == a[i][1]) cnt[1]++;
		else if (mx == a[i][2]) cnt[2]++;
		else if (mx == a[i][3]) cnt[3]++;
		if (cnt[1] > lim || cnt[2] > lim || cnt[3] > lim)
			typeD = 0;
	}
	if (typeA) {
		vector<int> arr;
		for (int i = 1; i <= n; ++i) {
			arr.push_back(a[i][1]);
		}
		sort(arr.begin(), arr.end(), greater<>());
		for (int i = 0; i < lim; ++i) {
			ans += arr[i];
		}
		cout << ans << endl;
		return;
	}
	if (typeB) {
		
	}
	if (typeD) {
		cout << " " << tet << endl;
		return;
	}
	
	ans = dfs(1, {0, 0, 0});
	cout << ans << endl;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while (t--) solve();

	return 0;
}
