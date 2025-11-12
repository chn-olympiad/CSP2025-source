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

string str(const string& s, int l, int r) {
	return s.substr(l, r - l + 1);
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n, q; cin >> n >> q;
	vla<pair<string, string>> a(n + 1);
	vla<pair<string, string>> b(n + 1);
	vi o(n + 1), nn(n + 1);
	F (i, 1, n) {
		cin >> a[i].first >> a[i].second;
		nn[i] = sz(a[i].first);
	}
	iota(all(o), 0);
	sort(all1(o), [&](int x, int y) {
		return nn[x] < nn[y];
	});
	F (i, 1, n) {
		b[i] = a[o[i]];
		#ifdef LOCAL
			assert(sz(b[i].first) >= sz(b[i-1].first));
		#endif
	}
	a = move(b);
	while (q--) {
		string x, y; cin >> x >> y;
		if (sz(x) != sz(y)) {
			cout << "0\n"; continue;
		}
		int m = sz(x);
		int l = -1, r = -1;
		fir (i, 0, m) {
			if (x[i] != y[i]) {
				if (l == -1) l = i;
				r = i;
			}
		}
		#ifdef LOCAL
			assert(~l && ~r);
		#endif
		int ans = 0;
		DF (i, n, 1) {
			int len = sz(a[i].first);
			if (len < r - l + 1) break;
			F (j, 0, m - len) {
				int L = j, R = j + len - 1;
				if (L <= l && R >= r && str(x, L, R) == a[i].first && str(y, L, R) == a[i].second) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}