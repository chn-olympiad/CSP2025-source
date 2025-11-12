#include <bits/stdc++.h>
using namespace std;
#define gcd std::__gcd
#define ctz __builtin_ctzll
#define popcount __builtin_popcountll
template<class T> constexpr T lowbit(T x) {return x&-x;}
template<class T> constexpr T lg(T x) {return x==0?0:std::__lg(x);}

template<class T> ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (int i = 0, n = v.size(); i < n; out << (++i < n ? ", " : "")) out << v[i];
	return out << "]";
}
template <class A, class B> ostream& operator<< (ostream& out, const pair<A, B>& p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
template <class A, class B> istream& operator>> (istream& in, pair<A, B>& p) {
	return in >> p.first >> p.second;
}

#undef assert
#ifdef SPN_LOCAL
#define FILE(x) ((void)0)
#define FLOCAL(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define debug(x) (cerr<<"On Line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl)
void _o(auto&&...x)
{int f=1;((cerr<<(f?"":", ")<<x,f=0),...);}
#define mdebug(...) (cerr<<"On Line "<<__LINE__<<": {"<<#__VA_ARGS__<<"} = [",_o(__VA_ARGS__),cerr<<"]\n")
#define assert(x) do{if(!(x))cerr<<"Assertion Failed on Line "<<__LINE__<<endl,exit(0);}while(0)
#else
#define FILE(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define FLOCAL(x) ((void)0)
#define debug(x) ((void)0)
#define mdebug(...) ((void)0)
#define assert(x) ((void)0)
#endif //SPN_LOCAL

template <const int mod>
struct mod32 {
	int val;
	static constexpr int norm(int x) {return x < 0 ? x + mod : x;}
	mod32() : val(0) {}
	mod32(int x) : val(norm(x % mod)) {}
	mod32<mod>& operator+= (const mod32<mod>& x) {
		return val += x.val, val >= mod ? val -= mod : val, *this;
	}
	mod32<mod>& operator-= (const mod32<mod>& x) {
		return val -= x.val, val < 0 ? val += mod : val, *this;
	}
	mod32<mod>& operator*= (const mod32<mod>& x) {
		return val = static_cast<long long>(val) * x.val % mod, *this;
	}
	mod32<mod> pow(long long b) const {
		mod32<mod> res = 1, a = *this;
		for (; b; a *= a, b >>= 1) {
			if (b & 1) res *= a;
		} return res;
	}
	mod32<mod> operator~ () const {return pow(mod - 2);}
	mod32<mod>& operator/= (const mod32<mod>& x) {return *this *= ~x;}

	mod32<mod> operator+ (const mod32<mod>& x) const {
		return mod32<mod>(*this) += x;
	}
	mod32<mod> operator- (const mod32<mod>& x) const {
		return mod32<mod>(*this) -= x;
	}
	mod32<mod> operator* (const mod32<mod>& x) const {
		return mod32<mod>(*this) *= x;
	}
	mod32<mod> operator/ (const mod32<mod>& x) const {
		return mod32<mod>(*this) /= x;
	}
};
template <const int mod> ostream& operator<< (ostream& out, const mod32<mod>& x) {
	return out << x.val;
}
template <const int mod> istream& operator>> (istream& in, mod32<mod>& x) {
	return in >> x.val;
}
using mint = mod32<998244353>;

const int N = 505;

int n, m, c[N];
char s[N];
mint fac[N];

namespace Sub1 {
	pair<int, int> p[N];
	int check() {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= p[i].first || s[i] == '0') cnt++;
		}
		return n - cnt;
	}
	void _main() {
		for (int i = 1; i <= n; i++) p[i].first = c[i], p[i].second = i;
		sort(p + 1, p + n + 1);
		int res = 0;
		do {
			if (check() >= m) res++;
		} while (next_permutation(p + 1, p + n + 1));
		cout << res;
	}
}

namespace Sub2 {
	mint f[N][N];
	void _main() {
		mint res = fac[n];
		for (int i = 0; i <= n; i++) f[0][i] = 1;
		sort(c + 1, c + n + 1);
		for (int i = 1; i <= n; i++) {   // position
			for (int j = 1; j <= n; j++) {   // people
				if (s[i] == '0') f[i][j] = f[i - 1][j - 1] * j;
				else {
					int cnt = 0;
					for (int k = 1; k <= j; k++) {
						if (c[k] < i) cnt++;
					}
					f[i][j] = f[i - 1][j - 1] * cnt;
				}
			}
		}
		cout << res - f[n][n];
	}
}

void _main() {
	fac[0] = 1;
	for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i;
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 10) return Sub1::_main(), void();
	cout << fac[n];
} signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr), cerr.tie(nullptr);
	FILE("employ");
	FLOCAL("employ4");

	int t = 1; for (/*cin >> t*/; t--; ) _main();
	return 0;
}

// expected 8pts.
