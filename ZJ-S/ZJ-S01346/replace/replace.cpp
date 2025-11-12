#include <bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define uint unsigned int
using namespace std;

namespace REPLACE {

const int N = 2e5 + 10;
const int M = 1e7 + 10;
const ull MOD = 1e9 + 123;
const ull BASE = 131;
const ull MOD2 = 1e9 + 9;
const ull BASE2 = 11451;
int n, Q, pos[2][N], qpos[N];

map<array<ull, 4>, int> idx; int m;

int nxt[26][M], ptot = 0, rt[2][N];
int Insert(int& rt, string s) {
	if (!rt) rt = ++ ptot;
	int p = rt;
	for (char c : s) {
		int x = c - 'a';
		if (!nxt[x][p]) nxt[x][p] = ++ ptot;
		p = nxt[x][p];
	}
	return p;
}
int Find(int rt, string s) {
	int p = rt;
	for (char c : s) {
		int x = c - 'a';
		if (!nxt[x][p]) break;
		p = nxt[x][p];
	}
	return p;
}
int dfncnt, dfn[M], R[M], Ans[N];
void DFS1(int u) {
	dfn[u] = ++ dfncnt;
	for (int i = 0; i < 26; i ++) if (nxt[i][u]) DFS1(nxt[i][u]);
	R[u] = dfncnt; return ;
}
vector<int> vec[M], qry[M];

int tr[M];
void add(int u, int k) { for (int i = u; i <= dfncnt; i += i & -i) tr[i] += k; }
int query(int u) { int r = 0; for (int i = u; i; i ^= i & -i) { r += tr[i]; } return r; }

void DFS2(int u) {
	for (int x : vec[u]) add(dfn[pos[1][x]], 1), add(R[pos[1][x]] + 1, -1);
	for (int x : qry[u]) Ans[x] = query(dfn[qpos[x]]);
	for (int i = 0; i < 26; i ++) if (nxt[i][u]) DFS2(nxt[i][u]);
	for (int x : vec[u]) add(dfn[pos[1][x]], -1), add(R[pos[1][x]] + 1, 1);
}

void main() {
	cin >> n >> Q;
	for (int i = 1; i <= n; i ++) {
		string s, t; cin >> s >> t;
		if (s == t) continue;
		int p = 0; while (s[p] == t[p]) ++ p;
		int q = s.size() - 1; while (s[q] == t[q]) q --;
		ull hsh1 = 0, hsh2 = 0, hsh3 = 0, hsh4 = 0;
		for (int i = p; i <= q; i ++) 
			hsh1 = (hsh1 * BASE + s[i] - 'a') % MOD, 
			hsh2 = (hsh2 * BASE + t[i] - 'a') % MOD,
			hsh3 = (hsh3 * BASE2 + s[i] - 'a') % MOD2, 
			hsh4 = (hsh4 * BASE2 + t[i] - 'a') % MOD2;
		if (idx.find({hsh1, hsh2, hsh3, hsh4}) == idx.end()) idx[{hsh1, hsh2, hsh3, hsh4}] = ++ m;
		int r = idx[{hsh1, hsh2, hsh3, hsh4}];
		string pre, suf;
		for (int i = p - 1; i >= 0; i --) pre.push_back(s[i]);
		for (int i = q + 1; i < (int)s.size(); i ++) suf.push_back(t[i]);
		pos[0][i] = Insert(rt[0][r], pre), pos[1][i] = Insert(rt[1][r], suf);
	}
	for (int i = 1; i <= m; i ++) DFS1(rt[1][i]);
	for (int i = 1; i <= n; i ++) vec[pos[0][i]].push_back(i);
	for (int i = 1; i <= Q; i ++) {
		string s, t; cin >> s >> t;
		int p = 0; while (s[p] == t[p]) ++ p;
		int q = s.size() - 1; while (s[q] == t[q]) q --;
		ull hsh1 = 0, hsh2 = 0, hsh3 = 0, hsh4 = 0;
		for (int i = p; i <= q; i ++) 
			hsh1 = (hsh1 * BASE + s[i] - 'a') % MOD, 
			hsh2 = (hsh2 * BASE + t[i] - 'a') % MOD,
			hsh3 = (hsh3 * BASE2 + s[i] - 'a') % MOD2, 
			hsh4 = (hsh4 * BASE2 + t[i] - 'a') % MOD2;
		if (idx.find({hsh1, hsh2, hsh3, hsh4}) == idx.end()) continue;
		int r = idx[{hsh1, hsh2, hsh3, hsh4}];
		string pre, suf;
		for (int i = p - 1; i >= 0; i --) pre.push_back(s[i]);
		for (int i = q + 1; i < (int)s.size(); i ++) suf.push_back(t[i]);
		qpos[i] = Find(rt[1][r], suf); qry[Find(rt[0][r], pre)].push_back(i);
	}
	for (int i = 1; i <= m; i ++) DFS2(rt[0][i]);
	for (int i = 1; i <= Q; i ++) cout << Ans[i] << "\n";
}

}

int main() {
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	REPLACE::main();
	return 0;
}