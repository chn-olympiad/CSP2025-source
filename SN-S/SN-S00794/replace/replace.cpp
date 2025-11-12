#include <bits/stdc++.h>
using namespace std;

namespace gxk {
	void main() ;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	gxk::main();
	return 0;
}

namespace gxk {
	const int maxm = 6000010;
	
	struct acamnode {
		int dp;
		int son[29];
		int fail;
	} ;
	
	struct acam {
		acamnode nodes[maxm];
		vector <int> G[maxm];
		int cnt;
		void add(string s) {
			int now = 1, nn = s.length();
			for (int i = 0; i < nn; i++) {
				int j;
				if (s[i] == '1') j = 26;
				else if (s[i] == '2') j = 27;
				else if (s[i] == '3') j = 28;
				else {
					j = s[i] - 'a';
				}
				if (!nodes[now].son[j]) {
					nodes[now].son[j] = ++cnt;
//					cout << cnt << '\n';
				}
				now = nodes[now].son[j];
			}
//			cout << '\n';
			nodes[now].dp++;
			return ;
		}
		void getfail() {
			queue <int> q;
			for (int i = 0; i < 29; i++) {
				int now = nodes[1].son[i];
				if (now) {
					nodes[now].fail = 1;
					G[1].push_back(now);
					q.push(now);
//					cout << now << ' ' << 1 << '\n';
				} else {
					nodes[1].son[i] = 1;
				}
			}
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int i = 0; i < 29; i++) {
					int &now = nodes[u].son[i], v = nodes[nodes[u].fail].son[i];
					if (!now) {
						now = v;
					} else {
						nodes[now].fail = v;
//						cout << now << ' ' << v << endl;
						G[v].push_back(now);
						q.push(now);
					}
				}
			}
			return ;
		}
		void dfs(int u, int nowdp) {
			nowdp += nodes[u].dp;
			nodes[u].dp = nowdp;
//			cout << u << ' ' << nodes[u].dp << '\n';
			for (int i = 0; i < G[u].size(); i++) {
				int now = G[u][i];
				dfs(now, nowdp);
			}
			return ;
		}
		int solve(string s) {
			int now = 1, nn = s.length();
			long long ress = 0;
			for (int i = 0; i < nn; i++) {
				int j;
				if (s[i] == '1') j = 26;
				else if (s[i] == '2') j = 27;
				else if (s[i] == '3') j = 28;
				else {
					j = s[i] - 'a';
				}
				now = nodes[now].son[j];
				ress += nodes[now].dp;
			}
			return ress;
		}
	} t[2];
	
	string a, b, c;
	int n, m;
	
	void findc() {
		c.clear();
		int len = a.length();
		int idx1 = -1, idx2 = len;
		while (a[idx1 + 1] == b[idx1 + 1]) {
			idx1++;
			if (idx1 == len - 1) {
//				for (int i = 0; i < len; i++) {
//					cout << a[i];
//				}
//				cout << '\n';
				t[1].add(a);
				return ;
			}
		}
		while (a[idx2 - 1] == b[idx2 - 1]) {
			idx2--;
		}
		for (int i = 0; i <= idx1; i++) {
			c.push_back(a[i]);
		}
		c.push_back('1');
		for (int i = idx1 + 1; i < idx2; i++) {
			c.push_back(a[i]);
		}
		c.push_back('2');
		for (int i = idx1 + 1; i < idx2; i++) {
			c.push_back(b[i]);
		}
		c.push_back('3');
		for (int i = idx2; i < len; i++) {
			c.push_back(a[i]);
		}
//		for (int i = 0; i < c.length); i++) {
//			cout << c[i];
//		}
//		cout << '\n';
		t[0].add(c);
		return ;
	}
	
	void solvec() {
		c.clear();
		int len = a.length();
		int idx1 = -1, idx2 = len;
		while (a[idx1 + 1] == b[idx1 + 1]) {
			idx1++;
			if (idx1 == len - 1) {
//				for (int i = 0; i < len; i++) {
//					cout << a[i];
//				}
//				cout << '\n';
				cout << t[1].solve(a) << '\n';
				return ;
			}
		}
		while (a[idx2 - 1] == b[idx2 - 1]) {
			idx2--;
		}
		for (int i = 0; i <= idx1; i++) {
			c.push_back(a[i]);
		}
		c.push_back('1');
		for (int i = idx1 + 1; i < idx2; i++) {
			c.push_back(a[i]);
		}
		c.push_back('2');
		for (int i = idx1 + 1; i < idx2; i++) {
			c.push_back(b[i]);
		}
		c.push_back('3');
		for (int i = idx2; i <= n; i++) {
			c.push_back(a[i]);
		}
//		for (int i = 0; i < c.length(); i++) {
//			cout << c[i];
//		}
//		cout << '\n';
		cout << t[0].solve(c) << '\n';
		return ;
	}
	
	void main() {
		t[0].cnt = t[1].cnt = 1;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b;
			findc();
		}
//		cout << 1 << endl;
		t[0].getfail();
//		cout << 1 << endl;
		t[0].dfs(1, 0);
//		cout << 1 << endl;
		t[1].getfail();
//		cout << 1 << endl;
		t[1].dfs(1, 0);
//		cout << 1 << endl;
		
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;
			solvec();
		}
		
		return ;
	}
}
