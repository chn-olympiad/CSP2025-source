// 将那云层也跨越
// Think twice, code once.
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

const long long mod = 11451419191, base = 2333;

int n, m, ans[200005];
struct pairstr {
	string fr, tl;

	pairstr() = default;
	pairstr(const string &f, const string &t): fr(f), tl(t) {}
};
struct node {
	vector<pairstr> opt;
	vector<pair<int, pairstr>>qry;
};
node vec[200005];
int idx;
map<long long, int> mpid;
struct Trie {
	int tot, trie[5000005][26];

	void clear() {tot = 0; memset(trie[0], 0, sizeof(trie[0])); return;}
	int insert(string &s) {
		int now = 0;
		for (char ch : s) {
			int c = ch - 'a';
			if (!trie[now][c]) {
				trie[now][c] = ++tot;
				memset(trie[tot], 0, sizeof(trie[tot]));
			}
			now = trie[now][c];
		}
		return now;
	}
	int query(string &s) {
		int now = 0;
		for (char ch : s) {
			int c = ch - 'a';
			if (!trie[now][c]) return now;
			now = trie[now][c];
		}
		return now;
	}
} tr1, tr2;
vector<int> opts[5000005], qrys[5000005];
int qid[200005];
struct BIT {
	int w[5000005];

	void update(int pos, int val) {
		for (; pos < 5000005; pos += pos & -pos) w[pos] += val;
		return;
	}
	int query(int pos) {
		int res = 0;
		for (; pos >= 1; pos -= pos & -pos) res += w[pos];
		return res;
	}
} bit;
int timer, dfn[5000005], siz[5000005];

inline void getstr(string &s1, string &s2, string &fr, string &tl) {
	int L = 0;
	while (s1[L] == s2[L]) L++;
	fr = s1.substr(0, L);
	reverse(fr.begin(), fr.end());
	int R = s1.length() - 1;
	while (s1[R] == s2[R]) R--;
	tl = s1.substr(R + 1);
	s1 = s1.substr(L, R - L + 1);
	s2 = s2.substr(L, R - L + 1);
	return;
}
void init(int now) {
	dfn[now] = ++timer, siz[now] = 1;
	for (int i = 0; i < 26; i++)
		if (tr2.trie[now][i]) init(tr2.trie[now][i]), siz[now] += siz[tr2.trie[now][i]];
	return;
}
void dfs(int now) {
	for (int i : opts[now]) bit.update(dfn[i], 1), bit.update(dfn[i] + siz[i], -1);
	for (int i : qrys[now]) ans[i] = bit.query(dfn[qid[i]])/* , eprintf("qry %d\n", qid[i]) */;
	for (int i = 0; i < 26; i++)
		if (tr1.trie[now][i]) dfs(tr1.trie[now][i]);
	for (int i : opts[now]) bit.update(dfn[i], -1), bit.update(dfn[i] + siz[i], 1);
	opts[now].clear(), qrys[now].clear();
	return;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 == s2) continue;
		string fr, tl;
		getstr(s1, s2, fr, tl);
		long long hsh = 0;
		for (int i = 0; i < (int)s1.length(); i++) {
			int c = (s1[i] - 'a') * 26 + s2[i] - 'a';
			hsh = (hsh * base + c) % mod;
		}
		if (!mpid.count(hsh)) mpid[hsh] = ++idx;
		vec[mpid[hsh]].opt.emplace_back(fr, tl);
	}
	for (int i = 1; i <= m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.length() != s2.length()) continue;
		// if (i == 103) eprintf("%s\n%s\n", s1.c_str(), s2.c_str());
		string fr, tl;
		getstr(s1, s2, fr, tl);
		long long hsh = 0;
		for (int i = 0; i < (int)s1.length(); i++) {
			int c = (s1[i] - 'a') * 26 + s2[i] - 'a';
			hsh = (hsh * base + c) % mod;
		}
		if (!mpid.count(hsh)) continue;
		vec[mpid[hsh]].qry.emplace_back(i, pairstr(fr, tl));
	}
	for (int W = 1; W <= idx; W++) {
		if (vec[W].qry.empty()) continue;
		// eprintf("debug: %d\n", (int)vec[W].opt.size());
		// if (W == 101) {
		// 	for (int i = 0; i < 5000005; i++)
		// 		if (bit.w[i]) eprintf("%d\n", i);
			// for (int i = 0; i < 5000005; i++)
			// 	if (!qrys[i].empty()) eprintf("qry %d\n", i);
		// }
		tr1.clear(), tr2.clear();
		// if (W == 101) tr1.clears(), tr2.clears();
		for (pairstr &i : vec[W].opt) {
			// if (W == 101 && i.tl.empty()) eprintf("%s\n", i.fr.c_str());
			opts[tr1.insert(i.fr)].push_back(tr2.insert(i.tl));
		}
		for (pair<int, pairstr> &i : vec[W].qry) {
			// if (i.first == 103) eprintf("%s\n%s\n", i.second.fr.c_str(), i.second.tl.c_str());
			qrys[tr1.insert(i.second.fr)].push_back(i.first);
			qid[i.first] = tr2.insert(i.second.tl);
		}
		timer = 0;
		init(0);
		dfs(0);
	}
	// eprintf("%d\n", ans[103]);
	for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}