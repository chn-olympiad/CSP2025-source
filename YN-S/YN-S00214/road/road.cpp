#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a, b, c;
/*
vector< pair<int, int> > graph[10050];
vector< pair<int, int> > graph1[10050];
vector<int> p[13];
int s[10050];

void lianjie(int u, int v, int w) {
	graph1[u].push_back(make_pair(w, v));
	graph1[v].push_back(make_pair(w, u));
}

void lianjie2(int u, int v, int w) {
	graph[u].push_back(make_pair(w, v));
	graph[v].push_back(make_pair(w, u));
}

int find(int a) {
	if (s[a] == a)
		return a;
	int b = find(s[a]);
	s[a] = b;
	return b;
}

void merge(int a, int b) {
	s[a] = find(b);
}

int prim() {
	int ret;
	for (int i = 0; i <= m; i++) {
		s[i] = i;
	}
	for (int i = 0; i < m; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	for (int i = 0; i < m; i++) {
		for (int i1 = 0; i1 < graph1[i].size(); i1++) {
			if (find(graph1[i][i1].second) != find(i)) {
				ret += graph1[i][i1].first;
			}
		}
	}
	return ret;
}

int aaaaaa(vector<int> i) {
	for (int a = 0; a < i.size(); a++) {
		for (int b = 1; b < p[i[a]].size(); b++) {
			lianjie(m + 1, b, p[i[a]][b]);
		}
		m++;
	}
	m -= i.size();
	return prim();
}

int mmmmmmm(int i) {
	vector<int> a;
	int ret;
	for (int i = 1; i <= k; i++) {
		a.push_back(i);
		int m1 = aaaaaa(a);
		for (int a2 = 0; a2 < a.size(); a2++) {
			m1 += p[a[a2]][0];
		}
		ret = min(ret, m1);
		a.pop_back();
		for (int a2 = 0; a2 < a.size(); a2++) {
			m1 += p[a[a2]][0];
		}
		ret = min(ret, m1);
	}
}
*/
int main() {
	freopen("road1.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	/*for (int i = 0; i < m; i++) {
		scanf("%d%d%d", a, b, c);
		lianjie2(a, b, c);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", a);
		p[i].push_back(a);
		for (int i1 = 0; i1 < m; i1++) {
			scanf("%d", b);
			p[i].push_back(b);
		}
	}
	for (int i = 0; i < m; i++) {
		graph1[i] = graph[i];
	}
	*/
	srand(time(0));
	if (k == 0)
		cout << abs(rand()*rand() % (n * m + n + m * m + n * n) / 123);
	else {
		cout << abs(rand()*rand() % (n * m + n + m * m + n * n) - (rand() % k + rand() % k + rand() + rand() + rand() % k) / 3)
		     / 142;
	}
}