#include <bits/stdc++.h>
auto ckmin = [](auto& l, const auto& r) {
	return r < l ? l = r, true : false;
};
auto ckmax = [](auto& l, const auto& r) {
	return l < r ? l = r, true : false;
};
using namespace std;
#define F(i, j, k, ...) for (int i = (j), ##__VA_ARGS__; i <= (k); i++)
#define DF(i, j, k, ...) for (int i = (j), ##__VA_ARGS__; i >= (k); i--)
#define fir(i, j, k, ...) for (int i = (j), ##__VA_ARGS__; i < (k); i++)
using i64 = long long;
using u64 = unsigned long long;
using uint = unsigned;
using lf = double;
using pii = pair<int, int>;
using vi = vector<int>;
#define vla vector
#define sz(x) int(x.size())
#define pb emplace_back
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define Range(x, l, r) begin(x) + l, begin(x) + r + 1
template <typename T>
ostream& operator << (ostream& os, vla<T> t) {
	os << "["; bool fir = true;
	fir (i, 0, sz(t)) {
		os << (fir ? "" : ", ") << t[i];
		fir = false;
	} return os << "]";
}
void OTT(auto&&... x) {
	cerr << "["; bool fir = true;
	((cerr << (fir ? "" : ", ") << x), ...);
	cerr << "]\n";
}
#ifdef LOCAL
#define debug(...) cerr << "#" << __LINE__ << " " << #__VA_ARGS__ << " = ", OTT(__VA_ARGS__)
#else
#define debug(...) void(0)
#endif

using et = array<int, 3>;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
et e[M];
et ng[N], ee[N * 10];
int f[11][N];
int fa[N + 100];
et owo[11][N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	F (i, 1, m) {
		F (j, 0, 2) {
			cin >> e[i][j];
		}
	}
	vi a(k + 1);
	F (i, 1, k) { cin >> a[i];
		F (j, 1, n) {
			cin >> f[i][j];
			owo[i][j] = {n + i, j, f[i][j]};
		}
		sort(owo[i] + 1, owo[i] + 1 + n, [&](et& l, et& r) {
			return l[2] < r[2];
		});
	}

	sort(e + 1, e + 1 + m, [&](et& l, et& r) {
		return l[2] < r[2];
	});

	iota(all(fa), 0);
	auto find = [&](int x) {
		while (x != fa[x]) x = fa[x] = fa[fa[x]];
		return x;
	};
	auto merge = [&](int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		fa[x] = y;
		return true;
	};
	int tot = -1;
	F (i, 1, m) {
		auto [u, v, w] = e[i];
		if (merge(u, v)) {
			ng[++tot] = e[i];
		}
	}

	i64 ans = 1e18;
	auto solve = [&](int state) {
		i64 cost = 0;
		int tot = -1;
		fir (j, 0, k) {
			if (state >> j & 1) {
				cost += a[j + 1];
				int lst = tot;
				copy(owo[j + 1] + 1, owo[j + 1] + n + 1, ee + tot + 1);
				tot += n;
				inplace_merge(ee, ee + lst + 1, ee + tot + 1, [&](const et& l, const et& r) {
					return l[2] < r[2];
				});
			}
		}
		iota(all(fa), 0);
		int cnt = __builtin_popcount(state) + n;
		int j = 0;
		auto upd = [&](et& t) {
			auto [u, v, w] = t;
			if (merge(u, v)) {
				cost += w;
				cnt--;
			}
		};
		F (i, 0, tot) {
			while (j < n - 1 && ng[j][2] < ee[i][2]) {
				upd(ng[j]);
				j++;
			}
			upd(ee[i]);
		}
		while (j < n - 1 && cnt != 1) {
			upd(ng[j]);
			j++;
		}
		ckmin(ans, cost);
	};
	fir (i, 0, 1 << k) {
		solve(i);
	}
	cout << ans << "\n";
	return 0;
}