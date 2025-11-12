#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
template<typename T>

inline void read(T &x) {
	bool f = 1;
	x = 0;
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = !f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	x = (f ? x : -x);
	return ;
}
template<typename T>

inline void print(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
	return ;
}

const int N = 1e4+20, M = 1e6+1e5+10, K = 20;
int n, m, k;
ll ans;

struct node {
	int l, r;
	ll w;
} edge, noww;

bool operator < (node a, node b) {
	return a.w > b.w;
}
priority_queue<node>qu;
ll c[K], a[K][N];
int par[N];

int find(int id) {
	if (par[id] == id)
		return id;
	else
		return par[id] = find(par[id]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	read(m);
	read(k);
	for (int i = 1; i <= m; i++) {
		read(edge.l);
		read(edge.r);
		read(edge.w);
		qu.push(edge);
	}
	for (int i = 1; i <= k; i++) {
		read(c[i]);
		for (int j = 1; j <= n; j++) {
			read(a[i][j]);
			edge.l = n + i;
			edge.r = j;
			edge.w = a[i][j];
			qu.push(edge);
		}
	}
	for (int i = 1; i <= n + k; i++)
		par[i] = i;
	while (!qu.empty()) {
		noww = qu.top();
		qu.pop();
		int aa = find(noww.l), bb = find(noww.r);
		if (aa == bb)
			continue;
		ans = ans + noww.w;
		par[aa] = bb;
	}
	printf("%lld\n", ans);
	return 0;
}