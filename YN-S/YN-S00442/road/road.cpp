#include <bits/stdc++.h>
//#include <vector>

using namespace std;
using num = long long;

namespace sol {

	struct dsu {
		num n;
		vector<num> fa;
		dsu(num x) : n(x), fa(x) {
			iota(fa.begin(), fa.end(), 0);
		}
		num find(num x) {
			return fa[x] == x ? x : fa[x] = find(fa[x]);
		}
		void merge(num a, num b) {
			a = find(a), b = find(b);
			if (a != b) {
				fa[a] = b;
			}
		}
	};

	struct edge {
		num u, v, w;
		bool operator<(const edge &r) const {
			return w < r.w;
		}
	};

	num code = 0, n, k;
	num kruscal(num x, const vector<edge> &e) {
		dsu d(n + k + 1);
		num res = 0, cnt = 0;
		for (const edge &i : e) {
			num u = i.u, v = i.v, w = i.w;
			if (d.find(u) == d.find(v) || (u > n && !((code >> (u - n - 1)) & 1)) || (v > n && ((code >> (v - n - 1)) & 1))) {
				continue;
			}
			d.merge(u, v);
			res += w;
			++cnt;
			if (cnt == x - 1) {
				break;
			}
		}
		return res;
	}

//	void inp_merge(vector<edge> &a, vector<edge> &b, vector<edge> &c) {
//		vector<edge> cc(a.size() + b.size());
//		merge(a.begin(), a.end(), b.begin(), b.end(), cc.begin());
//		c = cc;
//	}

	void run() {
		ios::sync_with_stdio(0), cin.tie(0);
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		num m;
		cin >> n >> m >> k;
//    vector<vector<pair<num, num>> g(n + 1);
		vector<edge> e(m);
		for (num i = 0; i < m; ++i) {
			num u, v, w;
			cin >> u >> v >> w;
			e[i] = {u, v, w};
		}
		auto ee = e;
		ee.resize(m + n * k);
		num idx = m;
		sort(e.begin(), e.end());
		vector<num> c(k + 1);
		vector<vector<edge>> p(k + 1, vector<edge>(n));
		for (num i = 1; i <= k; ++i) {
			cin >> c[i];
			for (num j = 0; j < n; ++j) {
				p[i][j].u = n + i;
				p[i][j].v = j + 1;
				cin >> p[i][j].w;
				ee[idx++] = p[i][j];
			}
			sort(p[i].begin(), p[i].end());
		}
		sort(ee.begin(), ee.end());
//		num cnt = 0, tot = 0, ori = kruscal(n, e);
//		vector<num> choose(k + 1);
//		for (num i = 1; i <= k; ++i) {
//			vector<edge> ee(e.size() + n);
//			merge(e.begin(), e.end(), p[i].begin(), p[i].end(), ee.begin());
//			num val = kruscal(n + i, ee) + c[i];
//			if (val < ori) {
//				choose[i] = 1;
//				++cnt;
//				tot += c[i];
//			}
//		}
//		vector<edge> ee(e);
//		for (num i = 1; i <= k; ++i) {
//			if (choose[i]) {
//				ee.insert(ee.end(), p[i].begin(), p[i].end());
//			}
//		}
//		sort(ee.begin(), ee.end());
//		cout << kruscal(n + cnt, ee) + tot;
		num ans = 0x3f3f3f3f3f3f3f3f;
		for (; code < (1 << k); ++code) {
			num cnt = 0, tot = 0;
			for (num j = 0; j < k; ++j) {
				if ((code >> j) & 1) {
					tot += c[j + 1];
					++cnt;
				}
			}
//			vector<edge> ee(cnt * n);
//			num cur = 0;
//			for (num j = 0; j < k; ++j) {
//				if ((i >> j) & 1) {
//					copy(p[j + 1].begin(), p[j + 1].end(), ee.begin() + cur);
//					cur += n;
//				}
//			}
//			sort(ee.begin(), ee.end());
//			vector<edge> e1(ee.size() + e.size());
//			merge(ee.begin(), ee.end(), e.begin(), e.end(), e1.begin());
//			ans = min(ans, kruscal(n + k, e1) + tot);
			ans = min(ans, kruscal(n + cnt, ee) + tot);
		}
		cout << ans;
	}

}

int main() {
	sol::run();

}