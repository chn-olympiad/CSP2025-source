#include <bits/stdc++.h>
using namespace std;
int head[10005], cnt;

struct node {
	int to, w, nxt;
} a[10005];
int dis[10005];

void add(int u, int v, int w) {
	cnt++;
	a[cnt].w = w;
	a[cnt].to = v;
	a[cnt].nxt = head[u];
	head[u] = cnt;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int tmpu, tmpv, tmpw;
	for (int i = 1; i <= m; i++) {
		cin >> tmpu >> tmpv >> tmpw;
		add(tmpu, tmpv, tmpw);
		add(tmpv, tmpu, tmpw);
	}

	return 0;
}
