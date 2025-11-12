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

#define int long long
const int N = 1e5 + 5;

int n;
struct node {
	pair<int, int> v[4];
	void init() {
		v[1].second = 1, v[2].second = 2, v[3].second = 3;
		sort(v + 1, v + 4, greater<pair<int, int>>());
	}
	int loss() const {return v[1].first - v[2].first;}
	bool operator< (const node& a) const {
		return loss() < a.loss();
	}
} a[N];
vector<node> vec[4];

void _main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].v[1].first >> a[i].v[2].first >> a[i].v[3].first;
		a[i].init();
	}
	for (int i = 1; i <= 3; i++) vec[i].clear();
	int res = 0;
	for (int i = 1; i <= n; i++) {
		vec[a[i].v[1].second].emplace_back(a[i]);
		res += a[i].v[1].first;
	}
	for (int i = 1; i <= 3; i++) {
		if ((int) vec[i].size() <= n / 2) continue;
		sort(vec[i].begin(), vec[i].end());
		int len = vec[i].size();
		for (int j = 0; j < len - n / 2; j++) {
			res -= vec[i][j].loss();
		}
	}
	cout << res << '\n';
} signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr), cerr.tie(nullptr);
	FILE("club");
	//FLOCAL("club5");

	int t = 1; for (cin >> t; t--; ) _main();
	return 0;
}

// expected 100pts.
// My Luogu user id is 928879. Please follow me, thank you meow.
