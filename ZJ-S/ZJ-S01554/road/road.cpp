#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x = 0, y = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * y;
}
const int M = 2e6 + 7, N = 1e4 + 7;
struct Edge{
	int u, v, w, id;
	bool operator < (const Edge &a)const{return w > a.w;}
}E[M], T[M];
int n, m, k, a[N], c;
int fa[N];
int Find(int x){return fa[x] == x ? x : fa[x] = Find(fa[x]);}
ll ans;
void Kru(Edge E[], int &m, int val) {
	priority_queue<Edge> p;
	for (int i = 1; i <= m + n; i++) p.push(E[i]);
	for (int i = 1; i <= n; i++) fa[i] = i;
	ll ret = 0;
	int tm = 0, cnt = 1;
//	puts("START!!!!!");
	while (!p.empty()) {
		Edge t = p.top(); p.pop();
		int fu = Find(t.u), fv = Find(t.v);
		if (fu == fv) continue;
//		printf("ADD u : %d v : %d w : %d id : %d\n",t.u, t.v, t.w, t.id);
		ret += t.w;
		cnt += (t.id > m);
		T[++tm] = t;
		fa[fu] = fv;
	}
	if (ans - ret - c >= val * cnt) {
		ans = ret + c + val * cnt;
		for (int i = 1; i <= tm; i++)
			E[i] = T[i], E[i].id = i;
		m = tm;
	}
//	puts("END!!!!!");
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	for (int i = 1; i <= m; i++) {
		E[i].u = read(), E[i].v = read(), E[i].w = read();
		E[i].id = i;
	}
	priority_queue<Edge> p;
	for (int i = 1; i <= m; i++) p.push(E[i]);
	for (int i = 1; i <= n; i++) fa[i] = i;
	int tm = 0;
	while (!p.empty()) {
		Edge t = p.top(); p.pop();
		int fu = Find(t.u), fv = Find(t.v);
		if (fu == fv) continue;
		ans += t.w;
		T[++tm] = t;
		fa[fu] = fv;
	}
	for (int i = 1; i <= tm; i++)
		E[i] = T[i], E[i].id = i;
	m = tm;
	
	for (int i = 1; i <= k; i++) {
		c = read();
		int minn = 1;
		for (int j = 1; j <= n; j++) {
			a[j] = read();
			if (a[j] < a[minn]) minn = j;
		}
//		c += 3 * minn;
		int p = m;
		for (int j = 1; j <= n; j++)
			E[++p] = (Edge){j, minn, a[j] - minn, m + j};
		Kru(E, m, minn);
	}
	printf("%lld", ans);
	return 0;
}
