#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int N = 2e5 + 5;
constexpr int LEN = 2e4;
int n, q;
string t1, t2;

struct Map {
	string s1, s2;
	int len;
	friend inline bool operator < (Map A, Map B) {
		return A.len < B.len;
	}
} mp[N];

//int pos[LEN];

string tmp;

int fnl;

inline void deal (int post1, int id) {
	tmp = t1;
	for (int i = 0; i < mp[id].len; ++ i) {
		if (tmp[i + post1] != mp[id].s1[i]) return;
		tmp[i + post1] = mp[id].s2[i];
	}
	fnl += (tmp == t2);
}

inline void solve1 () {
	sort(mp + 1, mp + n + 1);
	while (q --) {
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		fnl = 0;
		for (int i = 0; i < t1.size(); ++ i) {
			for (int j = 1; j <= n; ++ j) {
				if (i + mp[j].len - 1 >= t1.size()) break;
				deal(i, j);
			}
		}
		cout << fnl << '\n';
	}
}

int pos1, pos2;
inline void solve2 () {
	vector <pair <int, int>> v[LEN << 1];
	for (int i = 1; i <= n; ++ i) {
//		cerr << i << '\n';
		for (int j = 0; j < mp[i].len; ++ j) {
			if (mp[i].s1[j] == 'b') {
				pos1 = j;
				break;
			}
		}
		for (int j = 0; j < mp[i].len; ++ j) {
			if (mp[i].s2[j] == 'b') {
				pos2 = j;
				break;
			}
		}
		v[pos1 - pos2 + LEN].push_back({pos1, mp[i].len - pos2});
	}
//	for (int i = 1; i <= (n << 1); ++ i) sort(v[i].begin(), v[i].end);
	int qs1, qs2, cnt, lll, rrr;
	while (q --) {
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < t1.size(); ++ i) {
			if (t1[i] == 'b') {
				qs1 = i;
				break;
			}
		}
		for (int i = 0; i < t2.size(); ++ i) {
			if (t2[i] == 'b') {
				qs2 = i;
				break;
			}
		}
		lll = qs1, rrr = t2.size() - qs2, cnt = 0;
		for (int i = 0; i < v[qs1 - qs2 + LEN].size(); ++ i) {
			if (lll >= v[qs1 - qs2 + LEN][i].first and
			rrr >= v[qs1 - qs2 + LEN][i].second) cnt ++;
		}
		cout << cnt << '\n';
	}
}

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i) {
		cin >> mp[i].s1 >> mp[i].s2;
		mp[i].len = mp[i].s1.size();
	}
	if (n * q <= 100000) {
		solve1();
		return 0;
	}
//	cerr << "###";
	solve2();
	return 0;
}