#include <bits/stdc++.h>
using namespace std;
struct IO {
	IO() {
		freopen("replace.in", "r", stdin);
		freopen("replace.out", "w", stdout);
	}
	~IO() {
		fclose(stdin);
		fclose(stdout);
	}
};
IO io;
typedef pair<int, int> pii;
#define fi first
#define se second
#define pb emplace_back
const int N = 2e5 + 10, S = 5e6 + 10;
pii GetDiffer(const string &a, const string &b) {
	int len = a.size(), p1 = -1, p2 = -1;
	for (int i = 0; i < len; i++)
		if (a[i] != b[i]) {
			p1 = i;
			break;
		}
	if (p1 == -1) return { 0, -1 };
	for (int i = len - 1; i >= 0; i--)
		if (a[i] != b[i]) {
			p2 = i;
			break;
		}
	return { p1, p2 };
}
struct Edge {
	int v, nxt;
	Edge() { v = nxt = 0; }
	Edge(int _v, int _nxt) { v = _v, nxt = _nxt; }
};
int n, Q;
struct ACAM {
	int tot, fail[S], ch[S][26], ed[N];
	int eC, dfc, head[S], L[S], R[S];
	Edge e[S];
	ACAM() { eC = 0, tot = 1; }
	void AddEdge(int u, int v) {
		e[++eC] = Edge(v, head[u]);
		head[u] = eC;
	}
	void DFS(int u) {
		L[u] = ++dfc;
		for (int i = head[u]; i; i = e[i].nxt)
			DFS(e[i].v);
		R[u] = dfc;
	}
	void Ins(const string &s, int id) {
		int u = 1;
		for (auto i : s) {
			int &w = ch[u][i - 'a'];
			if (!w) w = ++tot;
			u = w;
		}
		ed[id] = u;
	}
	void Build() {
		queue<int> que;
		for (int i = 0; i < 26; i++) {
			if (ch[1][i]) fail[ch[1][i]] = 1, que.push(ch[1][i]);
			else ch[1][i] = 1;
		}
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			for (int i = 0; i < 26; i++) {
				if (ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], que.push(ch[u][i]);
				else ch[u][i] = ch[fail[u]][i];
			}
		}
		for (int i = 2; i <= tot; i++) AddEdge(fail[i], i);
		DFS(1);
	}
} t1, t2;
int rt1 = 1, rt2 = 2, tot = 2;
string s[N][2];
int len[N];
int dif[N];
bool BFCheck(const string &s1, const string &t1, const string &s2, const string &t2) {
	int l1 = s1.size(), l2 = s2.size();
	if (l1 > l2) return 0;
	for (int i = 0; i < l2; i++)
		if (s2.substr(i, l1) == s1) {
			if (s2.substr(0, i) + t1 + s2.substr(i + l1) == t2)
				return 1;
		}
	return 0;
}
struct Qry {
	int u, v, id;
	Qry() { u = v = id = 0; }
	Qry(int _u, int _v, int _id) { u = _u, v = _v, id = _id; }
};
vector<Qry> qs[S];
vector<int> d[S];
int ans[N];
int Work(const string &s, const string &t) {
	int len = s.size();
	pii ret = GetDiffer(s, t);
	int u = 1, v = 1;
	int ans = 0;
	for (int i = 0; i < len; i++) {
		u = t1.ch[u][s[i] - 'a'];
		v = t2.ch[v][t[i] - 'a'];
		if (i >= ret.se) {
			for (int j : d[ret.se - ret.fi + 1]) {
				int p = t1.ed[j], q = t2.ed[j];
				if (t1.L[p] <= t1.L[u] && t1.L[u] <= t1.R[p] && t2.L[q] <= t2.L[v] && t2.L[v] <= t2.R[q])
					ans++;
			}
		}
	}
	return ans;
}
int AddQ(const string &s, const string &t, int id) {
	int len = s.size();
	pii ret = GetDiffer(s, t);
	int di = ret.se - ret.fi + 1;
	int u = 1, v = 1;
	int ans = 0;
	for (int i = 0; i < len; i++) {
		u = t1.ch[u][s[i] - 'a'];
		v = t2.ch[v][t[i] - 'a'];
		if (i >= ret.se) {
			//cerr << "? " << u << " " << v << "\n";
			qs[di].pb(t1.L[u], t2.L[v], id);
		}
	}
	return ans;
}
struct BIT {
	int n, tr[S];
	void Mdf(int x, int v) {
		for (; x <= n; x += x & -x)
			tr[x] += v;
	}
	void Add(int l, int r, int v) {
		Mdf(l, v);
		Mdf(r + 1, -v);
	}
	int Ask(int x) {
		int res = 0;
		for (; x; x -= x & -x)
			res += tr[x];
		return res;
	}
} T;
struct Oper {
	int op, x, y, z, v;
	Oper() { op = x = y = z = v = 0; }
	Oper(int _op, int _x, int _y, int _z, int _v) { op = _op, x = _x, y = _y, z = _z, v = _v; }
};
Oper mdf[S];
int mC;
void AddAgain(int op, int x, int yl, int yr, int v) {
	//cerr << "AddAgain: " << op << " " << x << " " << yl << " " << yr << " " << v << "\n";
	mdf[++mC] = Oper(op, x, yl, yr, v);
}
void AddMdf(int l1, int r1, int l2, int r2) {
	//cerr << "Mdf: " << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
	AddAgain(2, l1, l2, r2, 1);
	AddAgain(2, r1 + 1, l2, r2, -1);
	//mdf[++mC] = Oper(2, r1, r2, 1);
	//if (l1 > 1) mdf[++mC] = Oper(2, l1 - 1, r2, -1);
	//if (l2 > 1) mdf[++mC] = Oper(2, r1, l2 - 1, -1);
	//if (l1 > 1 && l2 > 1) mdf[++mC] = Oper(2, l1 - 1, l2 - 1, 1);
}
void AddQry(int x, int y, int id) {
	mdf[++mC] = Oper(1, x, y, id, 0);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> Q;
	int mxdf = 0;
	//int sl1 = 0, sl2 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		len[i] = s[i][0].size();
		//sl1 += 2 * len[i];
		pii ret = GetDiffer(s[i][0], s[i][1]);
		mxdf = max(mxdf, dif[i] = ret.se - ret.fi + 1);
		t1.Ins(s[i][0], i);
		t2.Ins(s[i][1], i);
		d[dif[i]].pb(i);
	}
	t1.Build(), t2.Build();
	T.n = max(t1.tot, t2.tot) + 5;
	for (int i = 1; i <= Q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		//sl2 += 2 * t1.size();
		AddQ(t1, t2, i);
		//printf("%d\n", Work(t1, t2));
	}
	//cerr << sl1 << " " << sl2 << "\n";
	for (int i = 1; i <= mxdf; i++) {
		if (!qs[i].size() || !d[i].size()) continue;
		//cerr << "-------\n";
		mC = 0;
		for (int j : d[i]) {
			int p = t1.ed[j], q = t2.ed[j];
			//cerr << "Mdf: " << t1.L[p] << " " << t1.R[p] << " " << t2.L[q] << " " << t2.R[q] << "\n";
			AddMdf(t1.L[p], t1.R[p], t2.L[q], t2.R[q]);
		}
		for (auto j : qs[i])
			//cerr << "Qry: " << j.u << " " << j.v << " " << j.id << "\n",
			AddQry(j.u, j.v, j.id);
		//cerr << "-------\n";
		sort(mdf + 1, mdf + mC + 1, [](const Oper &a, const Oper &b) {
			return a.x != b.x ? a.x < b.x : a.op > b.op;
		});
		for (int j = 1; j <= mC; j++) {
			int op = mdf[j].op, y = mdf[j].y, z = mdf[j].z, v = mdf[j].v;
			if (op == 2) {
				//cerr << "Add: " << mdf[j].x << " " << y << " " << z << " " << v << "\n";
				T.Add(y, z, v);
			}
			else {
				//cerr << "Ask: " << mdf[j].x << " " << y << " " << z << ", " << T.Ask(y) << "\n";
				ans[z] += T.Ask(y);
			}
		}
	}
	for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
	return 0;
}