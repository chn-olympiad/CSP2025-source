#include<bits/stdc++.h>
#define N 10015
#define M 2000005
#define ll long long
using namespace std;
struct rec { int x, y, z; } e[M], te[M];
int n, m, tmp, K, w[15], fa[N], ve[15][N], mx, mn = 2e9;
ll ans, tans;
bool cmp(rec a, rec b) { return a.z < b.z; }
int get(int x) { return (x == fa[x]) ? x : fa[x] = get(fa[x]); }
void read(int &x) {
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 3) + (x << 1) + c - 48, c = getchar();
}
void krskl() {
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int x = get(e[i].x), y = get(e[i].y);
		if (x == y) continue;
		fa[x] = y, ans += e[i].z;
	}
}
void tkrskl() {
	sort(te + 1, te + tmp + 1, cmp);
	for (int i = 1; i <= tmp; i++) {
		int x = get(te[i].x), y = get(te[i].y);
		if (x == y) continue;
		fa[x] = y, tans += te[i].z;
		if (tans >= ans) return;
	}
	ans = tans;
}
void solvesp() {
	for (int i = 1; i <= K; i++)
		for (int j = 1; j <= n; j++)
			e[++m] = { n + i, j, ve[i][j] };
	for (int i = 1; i <= n + K; i++) fa[i] = i;
	krskl();
	printf("%lld", ans);
}
void add(int x) {
	for (int i = 1; i <= n; i++) te[++tmp] = { n + x, i, ve[x][i] };
}
void solvebf() {
	for (int i = 1; i <= n; i++) fa[i] = i;
	krskl();
	for (int i = 1; i < (1 << K); i++) {
		for (int j = 1; j <= m; j++) te[j] = e[j];
		tmp = m, tans = 0;
		for (int j = 1; j <= K; j++) {
			if ((i >> j - 1) & 1) add(j), fa[n+j] = n + j, tans += w[j];
		}
		for (int i = 1; i <= n; i++) fa[i] = i;
		tkrskl();
	}
	printf("%lld", ans);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(K);
	for (int i = 1; i <= m; i++) {
		read(e[i].x), read(e[i].y), read(e[i].z);
	}
	for (int i = 1; i <= K; i++) {
		read(w[i]), mx = max(mx, w[i]);
		for (int j = 1; j <= n; j++) {
			read(ve[i][j]), mn = min(mn, ve[i][j]);
		}
	}
	if (!mx && !mn || !K) solvesp();
	else solvebf();
	return 0;
}