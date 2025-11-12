#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 1e4 + 10, MAXM = 2e6 + 10;
struct DSU{
	int pa[MAXN];
	void Init(int n) {for(int i = 0; i <= n; i++) pa[i] = i;}
	int Find(int a) {
		if(pa[a] == a) return a;
		return pa[a] = Find(pa[a]);
	}
	void Union(int a, int b) {pa[Find(a)] = pa[Find(b)];}
	bool Query(int a, int b) {return Find(a) == Find(b);}
}dsu;
ll n, m, k, top = 0;
struct e{ll u, v, w;}Edge[MAXM];
bool cmp(e a, e b) {return a.w < b.w;}
ll c[15], cW[MAXN];
ll MST() {
	ll r = 0, cnt = 0;
	dsu.Init(n);
	for(int i = 0; i < top; i++) {
		ll u = Edge[i].u, v = Edge[i].v, w = Edge[i].w;
		if(dsu.Query(u, v)) continue;
		r += w, dsu.Union(u, v), cnt++;
		if(cnt == n - 1) break;
	}
	return r;
}
void solve1() {
	sort(Edge, Edge + top, cmp);
	cout << MST();
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 0; i < m; i++)
		scanf("%lld%lld%lld", &Edge[i].u, &Edge[i].v, &Edge[i].w);
	top = m;
	for(int i = 0, u; i < k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> cW[j];
			if(cW[j] == 0) u = j;
		}
		for(int j = 1; j <= n; j++) {
			if(j == u) continue;
			Edge[top].u = u, Edge[top].v = j, Edge[top].w = cW[j];
			top++;
		}
	}
	solve1();
	return 0;
}

