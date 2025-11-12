#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define f(i,x,y) for(int i=x;i<=y;++i)
class FoStar {
private:
	struct edge {
		int u, v, w, to;
	};
	vector<int> head;
	vector<edge> edges;
	int cnt = 0;
public:
	FoStar(size_t sz): head(sz), edges(sz) {}
	void add(int u, int v, int w) {
		edges[++cnt] = {u, v, w, head[u]};
		head[u] = cnt;
	}
	edge &operator[](int u) {
		return edges[u];
	}
};
class DSU {
private:
	vector<int> fa;
public:
	DSU(size_t sz): fa(sz) {
		iota(fa.begin(), fa.end(), 0);
	}
	int find(int x) {
		if (fa[x] == x)return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int u, int v) {
		int fu = find(u), fv = find(v);
		fa[fu] = fv;
	}
};
const int mod = 998244353;
int A(int x) {
	if (x <= 1) return 1;
	return x*A(x - 1) % mod;
}
const int maxn = 505;
int n, m, cnt;
vector<pair<int, int>> c, t;
string s;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	f(i, 1, n) {
		int tmp;
		cin >> tmp;
		c.push_back({i, tmp});
		if (tmp != 0) t.push_back({i, tmp});
	};
	vector<pair<int, int>> copy_c = c;
	if (t.size() < m) {
		cout << 0;
		exit(0);
	} else {
		do {
			int curpass = 0, res = 0, stop = 1;
			for (int i = 0; i < n; i++) {
				if (s[i] == '0') curpass++;
				else if (curpass >= c[i].second) curpass++;
				else res++;
			}
			if (res >= m) (cnt += 1) %= mod;
			next_permutation(c.begin(), c.end());
			for (int i = 0; i < n; i++) {
				if (c[i] != copy_c[i]) {
					stop = 0;
					break;
				}
			}
			if (stop) break;
		} while (1);
		cout << cnt << endl;
	}
	return 0;
}