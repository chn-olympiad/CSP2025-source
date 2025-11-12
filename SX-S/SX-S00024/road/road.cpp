#include <bits/stdc++.h>
using namespace std;
int n, m, k;

struct st {
	int to, nxt, w;
} e[400001]; //一会记得看
int cnt = 1;
priority_queue<pair<int, int> >q;
int a[11][100001];
long long c[201];

void add(int u, int v, int w) {
	e[u].to = v;
	e[u].w = w;
//	e[u].nxt = head[u];
	//head[u] = cnt++;
}

void d(int u) {
//	for (int i = 1; i; i = e[i].nxt) {
//		int v = e[i].to;
//		if (v == u)
//			continue;
//	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i < m; i++) {
		int a1, b, c1;
		cin >> a1 >> b >> c1;
		add(a1, b, c1);
		add(b, a1, c1);
	}
	//可以用scanf
	long long sumc1 = 0, sumc2 = 0;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		sumc1 += c[i];
		sumc1 %= 998244353;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			sumc2 += a[i][j];
			sumc2 %= 998244353;
		}
	}
	if (sumc1 == sumc2 == 0) {
		cout << 0;
		return 0;
	} else {
		d(1);
	}

	return 0;
}
