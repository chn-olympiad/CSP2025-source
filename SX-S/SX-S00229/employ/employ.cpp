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
const int N = 500 + 10;
constexpr int mod = 998244353;
auto Norm = [](int x) {
	x >= mod && (x -= mod);
	x < 0 && (x += mod);
	return x;
};
struct modint {
	int v;
	modint() : v(0) {}
	modint(int x) : v(Norm(x)) {}
	friend modint operator + (modint l, modint r) {
		modint res; res.v = l.v + r.v >= mod ? l.v + r.v - mod : l.v + r.v;
		return res;
	}
	friend modint operator - (modint l, modint r) {
		modint res; res.v = l.v < r.v ? mod + l.v - r.v : l.v - r.v;
		return res;
	}
	friend modint operator * (modint l, modint r) {
		modint res; res.v = 1LL * l.v * r.v % mod;
		return res;
	}
	void operator += (modint t) {
		*this = *this + t;
	}
	void operator -= (modint t) {
		*this = *this - t;
	}
	void operator *= (modint t) {
		*this = *this * t;
	}
};
modint power(modint base, i64 n = mod - 2) {
	modint res = 1;
	while (n) {
		if (n & 1) res = res * base;
		base = base * base;
		n /= 2;
	}
	return res;
}
ostream& operator << (ostream& os, modint t) {
	return os << t.v;
}
modint fac[N], inv[N];
modint binom(int n, int m) {
	if (n < m || m < 0) return 0;
	return fac[n] * inv[m] * inv[n - m];
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n, m; cin >> n >> m;
	fac[0] = 1;
	F (i, 1, n) fac[i] = fac[i - 1] * i;
	inv[n] = power(fac[n]);
	DF (i, n - 1, 0) {
		inv[i] = inv[i + 1] * (i + 1);
	}
	string s; cin >> s;
	s.insert(0, "#");
	vi c(n + 1);
	F (i, 1, n) cin >> c[i];

	if (m == 1) {
		modint ans = fac[n];
		sort(all1(c));
		modint res = 1;
		DF (i, n, 1) {
			if (n - c[i] + 1 - (n - i) <= 0) {
				res = 0; break;
			}
			res *= min(n, n - c[i]) - (n - i);
		}
		cout << ans - res << '\n';
		return 0;
	}


	if (n <= 10) {
		vi p(n + 1);
		iota(all1(p), 1);
		int ans = 0;
		do {
			int fail = 0;
			F (i, 1, n) {
				if (s[i] == '0' || fail >= c[p[i]]) fail++;
			}
			if (n - fail >= m) ans++;
		} while (next_permutation(all1(p)));
		cout << ans << "\n";
		return 0;
	}
	return 0;
}