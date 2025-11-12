#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5, L = 2.5e6 + 5;

bool st;

int n, q;

vector<int> wh[L];

struct acam {
	int ind, tr[L][26], fail[L];
	int add(string &str) {
		int now = 0;
		for (int i = 0; i < (int)str.size(); i ++) {
			if (!tr[now][str[i] - 'a'])
				tr[now][str[i] - 'a'] = ++ ind;
			now = tr[now][str[i] - 'a'];
		}
		return now;
	}
	
	vector<int> ftr[L];
	
	void build() {
		queue<int> q;
		for (int i = 0; i < 26; i ++)
			if (tr[0][i]) q.push(tr[0][i]);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < 26; i ++) {
				if (!tr[u][i])
					tr[u][i] = tr[fail[u]][i];
				else {
					fail[tr[u][i]] = tr[fail[u]][i];
					q.push(tr[u][i]);
				}
			}
		}
		for (int i = 1; i <= ind; i ++)
			ftr[fail[i]].push_back(i);
	}
} am1, am2;

int dfnd, dfnl[L], dfnr[L];

void dfs1(int u) {
	dfnl[u] = ++ dfnd;
	for (int v : am2.ftr[u]) dfs1(v);
	dfnr[u] = dfnd;
}

struct inquiry {
	int p2, id, coeff;
};
vector<inquiry> inq[L];

int tr[L];
void modify(int u, int x) {
	while (u <= am2.ind) tr[u] += x, u += (u & -u);
}
int query(int u) {
	int ans = 0;
	while (u) ans += tr[u], u -= (u & -u);
	return ans;
}

int ans[N];

void dfs2(int u) {
	for (int v : wh[u])
		modify(dfnl[v], 1), modify(dfnr[v] + 1, -1);
	for (inquiry &i : inq[u]) {
		ans[i.id] += i.coeff * query(dfnl[i.p2]);
	}
	for (int v : am1.ftr[u]) dfs2(v);
	for (int v : wh[u])
		modify(dfnl[v], -1), modify(dfnr[v] + 1, 1);
}

bool ed;

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		string s1, s2; cin >> s1 >> s2;
		int aa = am1.add(s1), bb = am2.add(s2);
		wh[aa].push_back(bb);
	}
	
	am1.build(), am2.build();
	
	for (int i = 1; i <= q; i ++) {
		string t1, t2; cin >> t1 >> t2;
		if (t1.size() != t2.size()) continue;
		int len = (int)t1.size(), nowl = 0;
		while (t1[nowl] == t2[nowl]) nowl ++;
		int nowr = len - 1;
		while (t1[nowr] == t2[nowr]) nowr --;
		int ordl[4] = {0, 0, nowl + 1, nowl + 1},
			ordr[4] = {len - 1, nowr - 1, len - 1, nowr - 1};
		for (int j = 0; j < 4; j ++) {
			int now1 = 0, now2 = 0;
			for (int k = ordl[j]; k <= ordr[j]; k ++) {
				now1 = am1.tr[now1][t1[k] - 'a'];
				now2 = am2.tr[now2][t2[k] - 'a'];
				inq[now1].push_back((inquiry){
					now2, i, (j == 1 || j == 2) ? -1 : 1
				});
			}
		}
	}
	
	dfs1(0);
	dfs2(0);
	
	for (int i = 1; i <= q; i ++) cout << ans[i] << "\n";
	
	return 0;
}