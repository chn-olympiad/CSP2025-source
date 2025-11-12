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
const int maxn = 2e5+5;
int n, q;
vector<pair<string, string>> s, t;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	f(i, 1, n) {
		string a, b;
		cin >> a >> b;
		s.push_back({a, b});
	}
	f(i, 1, q) {
		string a, b;
		cin >> a >> b;
		t.push_back({a, b});
	}
	for (auto [t1, t2] : t) {
		int cnt = 0;
		for (auto [s1, s2] : s) {
			f(i, 0, t1.size() - 1) {
				string tmp = t1, subtmp = t1.substr(i, s1.size());
				if (subtmp == s1) {
					f(j, i, s1.size() + i - 1) {
						tmp[j] = s2[j - i];
					}
				}
				if(tmp == t2) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}