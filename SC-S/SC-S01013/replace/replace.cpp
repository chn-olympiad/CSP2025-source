#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l;i <= r;++ i)
using ll = long long;
using ull = unsigned long long;
const ull bas = 37;
using namespace std;
using P = pair<int, int>;
int tt;
namespace wangcy {
	const int N = 2e5 + 10;
	int n, q, pw[N];
	bool fl = 1;
	struct node {
		string s, t;
		int p1, p2;
		vector <ull> has;
		inline ull calc(int l, int r) {
			if(!l) return has[r];
			return has[r] - has[l - 1];
		}
	}s[N];
	vector<int> g[N];
	map<pair<ull, ull>, int> cnt;
	inline bool cmp(int i2, int i1, int l1, int r1, int l2, int r2) {
		if (n >= 1e4) {
			if(r1 - l1 != r2 - l2) return false;
			if(s[i2].calc(l2, r2) != s[i1].calc(l1, r1) * pw[l2]) return false;
			return true;
		} else {
			if(r1 - l1 != r2 - l2) return false;
			E(i, l1, r1) {
				if(s[i1].s[i] != s[i2].s[l2 - l1 + i]) return false;
				if(s[i1].t[i] != s[i2].t[l2 - l1 + i]) return false;
			}
			return true;
		}
		return false;
	}
	ull calc(string S) {
		ull Q = 1, ret = 0;
		E(i, 0, (int)S.size() - 1) {
			ret = ret + S[i]* Q;
			Q *= bas;
		}
		return ret;
	}
	inline void Main() {
		cin >> n >> q;
		pw[0] = 1;
		E(i, 1, n) pw[i] = pw[i - 1] * bas;
		E(i, 1, n) {
			cin >> s[i].s >> s[i].t;
			s[i].has.resize(s[i].s.size() + 5);
			s[i].p1 = s[i].s.size();
			E(j, 0, (int)s[i].s.size()) if(s[i].s[j] != s[i].t[j]) s[i].p1 = min(j, s[i].p1), s[i].p2 = max(j, s[i].p2);
			ull Q = 1, ret = 0;
			E(j, 0, (int)s[i].s.size() - 1) {
				ret = ret + (s[i].s[j] * 97 + s[i].t[j])* Q;
				s[i].has[j] = ret;
				Q *= bas;
			}
			g[s[i].p2 - s[i].p1].emplace_back(i);
		}
		E(i, 1, q) {
			int ret = 0;
			string S, T;
			cin >> s[0].s >> s[0].t;
			if(S.size() != T.size()) {
				cout << "0\n";
				continue;
			}
			s[0].p1 = s[0].s.size(), s[0].p2 = 0, s[0].has.clear();
			s[0].has.resize(s[0].s.size() + 5);
			ull Q = 1, res = 0;
			E(j, 0, (int)s[0].s.size() - 1) {
				res = res + (s[0].s[j] * 97 + s[0].t[j])* Q;
				s[0].has[j] = res;
				Q *= bas;
			}
			E(j, 0, (int)s[0].s.size()) if(s[0].s[j] != s[0].t[j]) s[0].p1 = min(j, s[0].p1), s[0].p2 = max(j, s[0].p2);
			int dlt = s[0].p2 - s[0].p1;
			for(int ind: g[dlt]) {
				node x = s[ind];
				if(x.p1 > s[0].p1) continue;
				if(x.s.size() - x.p2 > s[0].s.size() - s[0].p2) continue;
				if(cmp(0, ind, 0, (int)s[ind].s.size() - 1, s[0].p1 - x.p1, s[0].p2 + s[ind].s.size() - x.p2 - 1)) ++ ret;
			}
			cout << ret << "\n";
		}
		return;
	}
}
int main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tt = 1;
	while(tt --) wangcy::Main();
	return 0;
}
// freopen 
// IOS SYNC WITH STDIO
// CLEAR CASES
// long long

// Ex : 100pts.