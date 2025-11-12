#include <cstdio>
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int read() {
	int num = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c & 15), c = getchar(); 
	}
	return num;
}

int n, m, ans[200000], Trie[11000000][26], tot, val[11000000], tm;
int pos[400000][2], L[400000], R[400000];
array<string, 2> S[400000];
vector<array<int, 3>> V;
vector<array<int, 2>> D;

void init() {
	n = read(), m = read();
	for (int i = 0; i < n; i ++) {
		cin >> S[i][0] >> S[i][1];
	}
	for (int i = n; i < n + m; i ++) {
		cin >> S[i][0] >> S[i][1];
	}
	for (int i = 0; i < n; i ++) {
		int k = S[i][0].size(), l = 0, r = k;
		while (l < k && S[i][0][l] == S[i][1][l]) {
			l ++;
		}
		if (l == k) {
			continue;
		}
		while (S[i][0][r - 1] == S[i][1][r - 1]) {
			r --;
		}
		L[i] = l, R[i] = r;
		int f = 0, g = 0;
		for (int j = l; j < r; j ++) {
			f = (59ll * f + S[i][0][j] - 'a' + 1) % 998244353;
			f = (59ll * f + S[i][1][j] - 'a' + 1) % 998244353;
			g = (97ll * g + S[i][0][j] - 'a' + 1) % 1000000007;
			g = (97ll * g + S[i][1][j] - 'a' + 1) % 1000000007;
		}
		V.push_back({f, g, i});
	}
	for (int i = n; i < n + m; i ++) {
		if (S[i][0].size() ^ S[i][1].size()) {
			continue;
		}
		int l = 0, r = S[i][0].size();
		while (S[i][0][l] == S[i][1][l]) {
			l ++;
		}
		while (S[i][0][r - 1] == S[i][1][r - 1]) {
			r --;
		}
		L[i] = l, R[i] = r;
		int f = 0, g = 0;
		for (int j = l; j < r; j ++) {
			f = (59ll * f + S[i][0][j] - 'a' + 1) % 998244353;
			f = (59ll * f + S[i][1][j] - 'a' + 1) % 998244353;
			g = (97ll * g + S[i][0][j] - 'a' + 1) % 1000000007;
			g = (97ll * g + S[i][1][j] - 'a' + 1) % 1000000007;
		}
		V.push_back({f, g, i});
	}
	sort(V.begin(), V.end());
	return;
}

void getDfn(int id) {
	val[id] = tm ++;
	for (int i = 0; i < 26; i ++) {
		if (Trie[id][i]) {
			getDfn(Trie[id][i]);
		}
	}
	return;
}

void dfs(int id, int &ind, int rt) {
	int p = ind;
	while (ind < D.size() && D[ind][0] == val[id] && D[ind][1] < n) {
		val[pos[D[ind ++][1]][1]] ++;
	}
	int q = ind;
	while (ind < D.size() && D[ind][0] == val[id]) {
		int now = rt, sid = D[ind ++][1];
		ans[sid - n] += val[now];
		for (int i = R[sid]; i < S[sid][0].size(); i ++) {
			ans[sid - n] += val[now = Trie[now][S[sid][0][i] - 'a']];
		}
	}
	for (int i = 0; i < 26; i ++) {
		if (Trie[id][i]) {
			dfs(Trie[id][i], ind, rt);
		}
	}
	for (int i = p; i < q; i ++) {
		val[pos[D[i][1]][1]] --;
	}
	return;
}

void calculate() {
	for (int st = 0; st < V.size();) {
		int ed = st, hash1 = V[st][0], hash2 = V[st][1], rt1 = tot ++, rt2 = tot ++;
		while (ed < V.size() && V[ed][0] == hash1 && V[ed][1] == hash2) {
			int now = rt1, id = V[ed ++][2];
			for (int i = L[id] - 1; ~i; i --) {
				int dgt = S[id][0][i] - 'a';
				if (!Trie[now][dgt]) {
					Trie[now][dgt] = tot ++;
				}
				now = Trie[now][dgt];
			}
			pos[id][0] = now, now = rt2;
			for (int i = R[id]; i < S[id][0].size(); i ++) {
				int dgt = S[id][0][i] - 'a';
				if (!Trie[now][dgt]) {
					Trie[now][dgt] = tot ++;
				}
				now = Trie[now][dgt];
			}
			pos[id][1] = now;
		}
		tm = 0, getDfn(rt1), D.clear();
		for (int i = st; i < ed; i ++) {
			D.push_back({val[pos[V[i][2]][0]], V[i][2]});
		}
		int ind = 0;
		sort(D.begin(), D.end()), dfs(rt1, ind, rt2), st = ed;
	}
	for (int i = 0; i < m; i ++) {
		printf("%d\n", ans[i]);
	}
	return;
}

void solve() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init(), calculate();
	return;
}

int main() {
	solve();
	return 0;
}