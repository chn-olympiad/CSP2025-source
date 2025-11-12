#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int mxn = 500 + 1;
constexpr int mod = 998244353;

inline long long save_subA(const int n, const int m) {
	if(true) {
		long long ans = 1;
		for(int i = 1; i <= n; i++)
			(ans *= i) %= mod;
		return ans;
	}
	return 0;
}

inline long long Fac(const int n) {
	long long ans = 1;
	for(int i = 1; i <= n; i++)
		(ans *= i) %= mod;
	return ans;
}

inline long long save_m1(const string &s, vector<int> &in) {
	const int lest = s.find('0');
	sort(in.begin(), in.end(), greater<>());
	int can_use = 0;
	for(auto &i: in) {
		if(i <= lest)
			break;
		can_use++;
	}
	return can_use * Fac(in.size() - 1) % mod;
}

int n, m;
string s;
vector<int> in;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	in.resize(n);
	for(auto &i: in)
		cin >> i;
	if(s.find('0') == string::npos)
		cout << save_subA(n, m);
	else if(m == 1)
		cout << save_m1(s, in);
	return 0;
}
