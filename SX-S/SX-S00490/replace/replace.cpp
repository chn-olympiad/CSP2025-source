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

const int N = 2e5 + 5, M = 5e6 + 5;
using ull = unsigned long long;
const ull base = 13331;

int n, q, m;
string s1, s2, t1, t2;
map<pair<ull, ull>, int> mp;
ull b[M], x[N], y[N];

long long ask() {
	if (t1.size() != t2.size()) return 0;
	int m = t1.size() - 1;
	vector<ull> h1(m + 1), h2(m + 1);
	for (int i = 1; i <= m; i++) h1[i] = h1[i - 1] * base + t1[i];
	for (int i = 1; i <= m; i++) h2[i] = h2[i - 1] * base + t2[i];
	//mdebug(h1, h2);
	long long res = 0;
	int lm = n, rm = 1;
	for (int i = 1; i <= m; i++) {
		if (h1[i - 1] != h2[i - 1]) {lm = i - 1; break;}
	}
	for (int i = m; i >= 1; i--) {
		if (h1[m] - h1[i] * b[m - i] != h2[m] - h2[i] * b[m - i]) {rm = i + 1; break;}
	}
	for (int l = 1; l <= lm; l++) {
		for (int r = rm; r <= m; r++) {
			if (r >= l) res += mp[{h1[r] - h1[l - 1] * b[r - l + 1], h2[r] - h2[l - 1] * b[r - l + 1]}];
		}
	}
	return res;
}

void _main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		ull h1 = 0, h2 = 0;
		for (char c : s1) h1 = h1 * base + c;
		for (char c : s2) h2 = h2 * base + c;
		mp[{h1, h2}]++, x[i] = h1, y[i] = h2;
	}
	b[0] = 1;
	for (int i = 1; i < M; i++) b[i] = b[i - 1] * base;
	while (q--) {
		cin >> t1 >> t2;
		t1 = '#' + t1, t2 = '#' + t2;
		cout << ask() << '\n';
	}
} signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr), cerr.tie(nullptr);
	FILE("replace");
	FLOCAL("replace2");

	int t = 1; for (/*cin >> t*/; t--; ) _main();
	return 0;
}

// expected 25pts.
