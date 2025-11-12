/*****************/
/*  road.cpp     */
/*****************/
/* Not Perfect, Expect 16/25 */
#include <bits/stdc++.h>
using namespace std;
const string FILE_NAME = "road";
ifstream is(FILE_NAME + ".in");
ofstream os(FILE_NAME + ".out");
//#define is cin
//#define os cout
//template <typename T> struct chain {
//	struct node {
//		T data;
//		node *next;
//	} *head = nullptr;
//	void push(const T&v) {
//		head = new node{v, head};
//	}
//};
struct DSU {
	vector<int> fa, size;
	DSU(int n) {
		fa = vector<int>(n);
		size = vector<int>(n, 1);
		for(int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}
	int query(int x) {
		return fa[x] == x ? x : fa[x] = query(fa[x]);
	}
	void merge(int x, int y) {
//		cout << "merge: " << x << " " << y << "\n";
//		for(int i = 0; i < fa.size(); ++i) cout << setw(3) << i; cout << "\n";
//		for(auto i : fa) cout << setw(3) << i; cout << "\n";
		int fax = query(x), fay = query(y);
//		for(auto i : fa) cout << setw(3) << i; cout << "\n";
		if(size[fax] > size[fay]) {
			size[fax] += size[fay];
			fa[fay] = fax;
		} else {
			size[fay] += size[fax];
			fa[fax] = fay;
		}
//		for(auto i : fa) cout << setw(3) << i; cout << "\n";
	}
};
long long sol(vector<tuple<int, int, int>> edges, const vector<int> &c, const vector<vector<int>> &a, int n, int m, int k, bitset<10> &&change) {
	long long ans = 0;
	DSU dsu(n + 1);
	for (int i = 1; i <= k; ++i) {
		if (change[i]) {
			ans += c[i];
			ans += a[i][i];
			for(int j = 1; j <= n; ++j) {
				edges.push_back({a[i][j], i, j});
			}
		}
	}
	sort(edges.begin(), edges.end());
	for (auto [w, x, y] : edges) {
		if (dsu.query(x) == dsu.query(y)) {
			continue;
		}
		ans += w;
		dsu.merge(x, y);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	is.tie(0);
	os.tie(0);
	int n, m, k;
	is >> n >> m >> k;
//	vector<chain<tuple<int, int, int>>> G(n + 1);
	vector<tuple<int, int, int>> edges;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		is >> u >> v >> w;
		edges.push_back({w, u, v});
	}
	vector<int> c(k + 1);
	vector<vector<int>> a(11, vector<int>(n + 1));
	for (int i = 1; i <= k; ++i) {
		is >> c[i];
		for(int j = 1; j <= n; ++j) {
			is >> a[i][j];
		}
	}
	long long ans = LLONG_MAX;
	if(k <= 7) {
		for(int status = 0; status < (1 << k); ++status) {
			ans = min(ans, sol(edges, c, a, n, m, k, bitset<10>(status)));
		}
	} else {
		// To solve
		ans = sol(edges, c, a, n, m, k, bitset<10>((1 << k) - 1));
	}
	os << ans;
	return 0;
}