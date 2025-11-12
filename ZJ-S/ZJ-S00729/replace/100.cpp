#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie() -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= r; i++)
#define R(i, r, l) for (int i = r; i >= l; i--)

// 1.5h 来 rush 这个题, 加油!

struct node {
	string pre, sufs, suft;
	int len;
};

const int N = 2e5 + 5, L = 5e6 + 6, M = L << 1, S = 26;

struct trie {
	int tot, ch[M][S], cnt[M];
	void modify(string& s, int dt, int u = 0) {
		for (auto w : s) {
			int c = w - 'a';
			if (!ch[u][c]) ch[u][c] = ++tot;
			u = ch[u][c];
		}
		cnt[u] += dt;
	}
	int query(string s, int u = 0, int res = 0) {
		for (auto w : s) {
			int c = w - 'a';
			res += cnt[u];
			u = ch[u][c];
			if (!u) return res;
		}
		res += cnt[u];
		return res;
	}
} tr;

int n, q, ans[N];
int tot, rt[L];
map < int, int > ch[M];
vi Q[M];
string prep[N], preq[N];

int get(char x, char y) {
	return (x - 'a') * 26 + y - 'a';
}
void insert(int& u, int pos, string& s, string& t, int id) {
	if (!u) u = ++tot;
	if (pos == sz(s)) {
		Q[u].pb(id);
		return;
	}
	insert(ch[u][get(s[pos], t[pos])], pos + 1, s, t, id);
}

node solve(string s, string t) {
	int p = 0, S = sz(s) - 1;
	string pre = "", sufs = "", suft = "";
	for (; s[p] == t[p]; pre += s[p++]);
	reverse(all(pre));
	for (; s[S] == t[S]; S--);
	L(j, p, sz(s) - 1) sufs += s[j], suft += t[j];
	return {pre, sufs, suft, S - p + 1};
}

void dfs(int u) {
	if (!u) return;
	for (auto id : Q[u]) {
		if (id <= n) tr.modify(prep[id], 1);
		else ans[id - n] = tr.query(preq[id - n]);
	}
	for (auto [key, v] : ch[u]) dfs(v);
	for (auto id : Q[u]) {
		if (id <= n) tr.modify(prep[id], -1);
	}
}

int main() {
	qio(), cin >> n >> q;
	L(i, 1, n) {
		string s, t;
		cin >> s >> t;
		if (s == t) continue;
		auto [pre, sufs, suft, len] = solve(s, t);
		prep[i] = pre;
		insert(rt[len], 0, sufs, suft, i);
//		cerr << len << ' ' << pre << ' ' << sufs << ' ' << suft << '\n';
	}
	L(i, 1, q) {
		string s, t;
		cin >> s >> t;
		auto [pre, sufs, suft, len] = solve(s, t);
		preq[i] = pre;
		insert(rt[len], 0, sufs, suft, i + n);
	}
	L(len, 1, L - 6) {
		dfs(rt[len]);
	}
	L(i, 1, q) cout << ans[i] << '\n';
	return 0;
}
