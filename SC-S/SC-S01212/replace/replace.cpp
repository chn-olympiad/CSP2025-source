#include <unordered_map>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const int N = 2e5 + 5;
int n, q, cnt, tot;
int head[N], used[1005][1005];
string pm[N << 1];
set<int> length;
queue<string> que;
unordered_map<string, int> mp;
struct edge {
	int to, next;
} e[N];
void add(int u, int v) {
	e[++tot] = {v, head[u]};
	head[u] = tot;
}
void bfs(string s, string en) {
	int res = 0;
	que.push(s);
	while (!que.empty()) {
		string p = que.front();
		que.pop();
		if (p == en) res++;
		for (int i = 0; i < p.size(); i++) {
			for (int len : length) {
				if (i + len > p.size()) continue;
				string pre = p.substr(0, i);
				string str = p.substr(i, len);
				string nxt = p.substr(i + len, p.size() - len - i);
				for (int i = head[mp[str]]; i; i = e[i].next) {
					int v = e[i].to;
					if (used[mp[str]][v]) continue;
					used[mp[str]][v] = 1;
					que.push(pre + pm[v] + nxt);
				}
			}
		}
	}
	printf("%d\n", res);
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (!mp[s1]) mp[s1] = ++cnt, pm[cnt] = s1;
		if (!mp[s2]) mp[s2] = ++cnt, pm[cnt] = s2;
		add(mp[s1], mp[s2]);
		length.insert(s1.size());
		length.insert(s2.size());
	}
	while (q--) {
		string s1, s2;
		cin >> s1 >> s2;
		bfs(s1, s2);
	}
	return 0;
}
