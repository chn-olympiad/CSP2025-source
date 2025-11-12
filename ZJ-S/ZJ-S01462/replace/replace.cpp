#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
bool st;
int tr[N][26], len[N], fail[N], fa[N][23], tot;
vector<int> to[N];
vector<pair<pair<int, int>, int>> Q[N], A[N];
bool ed;

int insert(string s) {
	int p = 0;
	for (int i = 0; i < s.size(); i ++ ) {
		int c = s[i] - 'a';
		if (!tr[p][c]) tr[p][c] = ++ tot, len[tot] = len[p] + 1;
		p = tr[p][c];
	}
	return p;
}

void build() {
	queue<int> q;
	for (int i = 0; i < 26; i ++ )
		if (tr[0][i])
			q.push(tr[0][i]);
	while (q.size()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < 26; i ++ )
			if (tr[t][i]) fail[tr[t][i]] = tr[fail[t]][i], q.push(tr[t][i]);
			else tr[t][i] = tr[fail[t]][i];
		to[fail[t]].push_back(t);
	}
}

int L[N], R[N], tt;

void dfs(int u) {
	for (int i = 1; i <= 22; i ++ ) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	L[u] = ++ tt;
	for (int v : to[u]) {
		fa[v][0] = u;
		dfs(v);	
	}
	R[u] = tt;
}

int tree[N];
inline void add(int x, int k) {
	for (int i = x; i <= tt; i += i & -i) tree[i] += k;
}
inline int ask(int x) {
	int res = 0;
	while (x) {
		res += tree[x];
		x -= x & -x;
	}
	return res;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> x(n + 5), y(n + 5);
	for (int i = 1; i <= n; i ++ ) {
		string s1, s2;
		cin >> s1 >> s2;
		x[i] = insert(s1), y[i] = insert(s2);
	}
	build();
	dfs(0);
	vector<int> ans(q + 5);
	for (int i = 1; i <= q; i ++ ) {
		string t1, t2;
		cin >> t1 >> t2;
		int s = 2e9, t = 0;
		for (int j = 0; j < t1.size(); j ++ ) {
			if (t1[j] != t2[j]) {
				s = min(s, j);
				t = max(t, j);
			}
		}
		int p1 = 0, p2 = 0;
		for (int j = 0; j < t1.size(); j ++ ) {
			p1 = tr[p1][t1[j] - 'a']; 
			p2 = tr[p2][t2[j] - 'a'];
			if (j >= t) {
				if (len[p1] < j - s + 1 || len[p2] < j - s + 1) continue;
				int j1 = p1, j2 = p2;
				for (int k = 22; k >= 0; k -- ) {
					if (len[fa[j1][k]] >= j - s + 1)
						j1 = fa[j1][k];
					if (len[fa[j2][k]] >= j - s + 1)
						j2 = fa[j2][k];
				}
				j1 = fa[j1][0], j2 = fa[j2][0];
				A[L[p1]].push_back({{L[p2], 1}, i});
				A[L[p1]].push_back({{L[j2], -1}, i});
				A[L[j1]].push_back({{L[p2], -1}, i});
				A[L[j1]].push_back({{L[j2], 1}, i});
			}
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		Q[L[x[i]]].push_back({{L[y[i]], R[y[i]]}, 1});
		Q[R[x[i]] + 1].push_back({{L[y[i]], R[y[i]]}, -1});
	}
	for (int i = 1; i <= tt; i ++ ) {
		for (auto j : Q[i]) {
			add(j.first.first, j.second);
			add(j.first.second + 1, -j.second);
		}
		for (auto j : A[i]) {
			ans[j.second] += j.first.second * ask(j.first.first);
		}
	}
	for (int i = 1; i <= q; i ++ ) cout << ans[i] << endl;
	return 0;
}