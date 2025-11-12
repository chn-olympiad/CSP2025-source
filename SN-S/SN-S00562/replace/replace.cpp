#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e6+10;
//array<int, 27> cla;

struct AC {
	vector<vector<int>> trie;
	vector<int> fail;
	vector<ll> f;
	vector<vector<int>> e;
	int tot;
	
	AC() {
		tot = -1;
		add();
	}
	
	int add() {
		++tot;
		trie.push_back(vector<int>(27, 0));
		fail.push_back(0);
		f.push_back(0);	
		e.push_back(vector<int>());
		return tot;
	}
	
	void insert(string s) {
//		cerr << "insert: " << s << '\n';
		int now = 0;
		for (char ch : s) {
//			int to = trie[now][ch-'a'];
			if (trie[now][ch-'a'] == 0) trie[now][ch-'a'] = add();
//			cerr << to << " - " << trie[now][ch-'a'] << '\n';
//			cerr << now << " -> " << trie[now][ch-'a'] << ' ' << tot << '\n';
			now = trie[now][ch-'a'];
		}
		++f[now];
//		cerr << now << "  f1\n";
	}
	
	void dfs(int x) {
		for (int y : e[x]) {
			f[y] += f[x];
			dfs(y);
		}
	}
	
	void build() {
		queue<int> que;
		for (int i=0; i<27; ++i) if (trie[0][i]) que.push(trie[0][i]);
		while (que.size()) {
			int x = que.front(); que.pop();
			for (int i=0; i<27; ++i) {
				int &y = trie[x][i];
				if (y) {
					fail[y] = trie[fail[x]][i];
					que.push(y);
				} else {
					y = trie[fail[x]][i];
				}
			}
		}
		for (int i=1; i<=tot; ++i) {
			e[fail[i]].push_back(i);
		}
		dfs(0);
	}
	
	ll query(string s) {
//		cerr << "query : " << s << '\n';
		ll res = 0;
		int now = 0;
		for (char ch : s) {
			int to = trie[now][ch-'a'];
//			cerr << now << " -> " << to << '\n';
			now = to;
//			cerr << now << " : " << f[now] << '\n';
			res += f[now];
		}
		return res;
	}
};

vector<AC> ac;

tuple<string, string, string> rp(const string &s, const string &t) {
	int fi = -1, se = 0;
	int sz = (int)s.size();
	for (int i=0; i<sz; ++i) {
		if (s[i] != t[i]) {
			if (fi == -1) fi = i;
			se = i;
		}
	}
	string a, b="{", c;
	if (fi != 0) a = s.substr(0, fi);
	if (se != sz-1) c = s.substr(se+1);
	return make_tuple(a + b + c, s.substr(fi, se-fi+1), t.substr(fi, se-fi+1));
}

map<string, int> sid;
int cnt = -1;
int n, q;

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
//	auto it = rp("aaa", "aab");
//	cout << get<0>(it) << ' ' << get<1>(it) << ' ' << get<2>(it) << '\n';
//	exit(0);

	cin >> n >> q;
	for (int i=1; i<=n; ++i) {
		string s, t;
		cin >> s >> t;
		if (s == t) continue;
		auto it = rp(s, t);
		if (sid.count(get<1>(it) + get<2>(it)) == 0) {
			sid[get<1>(it) + get<2>(it)] = ++cnt;
			ac.push_back(AC());
		}
		
		int id = sid[get<1>(it) + get<2>(it)];
		
//		cerr << i << ' '<< id << '\n';
//		cerr << get<0>(it) << ' ' << get<1>(it) << ' ' << get<2>(it) << '\n';
		ac[id].insert(get<0>(it));
	}
//	cerr << ac.size() << ' '<< cnt << "---\n";
	
	for (int i=0; i<=cnt; ++i) {
		ac[i].build();
	}
//	
//	cerr << "-----\n";
	for (int T=1; T<=q; ++T) {
		string s, t;
		cin >> s >> t;
		auto it = rp(s, t);
//		cerr << get<0>(it) << ' ' << get<1>(it) << ' ' << get<2>(it) << '\n';
		if (sid.count(get<1>(it) + get<2>(it)) == 0) {
			cout << 0 <<  '\n';
			continue;
		}
		int id = sid[get<1>(it) + get<2>(it)];
//		cerr << T << ' '<< id << '\n';
//		ac[id].insert(get<0>(it));
		cout << ac[id].query(get<0>(it)) << '\n';
	}
	
	return 0;
}

