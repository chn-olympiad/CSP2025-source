#include<bits/stdc++.h>
#define cs const
#define dif(a, b) ((a) ^ (b))
#define LL long long

using namespace std;

cs int MAXN = 1e4 + 20;
cs int MAXK = 15;

struct Edge {
	int from, to, weight;
	inline bool operator < (cs Edge ano) cs {
		if (weight ^ ano.weight)	return weight < ano.weight;
		return from < ano.from;
	}
};

int n, m, k;
int limn, limm, limk, limnk;
int anc[MAXN], ori[MAXN];
multiset<Edge> use;
multiset<Edge> edge;

int node[MAXK];
vector<Edge> more[MAXK];

LL ans = 0x3f3f3f3f3f3f3f3f;

inline int findAnc(int cur) {
	if (cur ^ anc[cur])
		anc[cur] = findAnc(anc[cur]);
	return anc[cur];
}
inline void unite(int a, int b) {
	anc[findAnc(a)] = findAnc(b);
	return;
}

inline void edgeSieve() {
	LL cur = 0;
	int need = n - 1;
	memcpy(anc + 1, ori + 1, sizeof(int) * limnk);
	for (cs Edge& e : edge) {
		if (findAnc(e.from) ^ findAnc(e.to)) {
			use.insert(e);
			cur += e.weight;
			unite(e.from, e.to);
			need--;
			if (!need)
				break;
		}
	}
	ans = min(ans, cur);
	return;
}

inline void solve(cs int& t) {
	LL cur = 0;
	int need = n - 1;
	for (int i = 1; dif(i, limk); ++i) {
		if (!((t >> (i - 1) & 1)))	continue;
		cur += node[i], need++;
		for (cs Edge& e : more[i])
			use.insert(e);
	}
	memcpy(anc + 1, ori + 1, sizeof(int) * limnk);
	for (cs Edge& e : use) {
		if (findAnc(e.from) ^ findAnc(e.to)) {
			cur += e.weight;
			unite(e.from, e.to);
			need--;
			if (!need)
				break;
		}
	}
	ans = min(ans, cur);
	for (int i = 1; dif(i, limk); ++i) {
		if (!((t >> (i - 1) & 1)))	continue;
		for (cs Edge& e : more[i])
			use.erase(e);
	}
	return;
}

int main() {
#ifndef DEBUG
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	cin >> n >> m >> k;
	limn = n + 1, limm = m + 1, limk = k + 1, limnk = n + k + 1;
	iota(ori + 1, ori + limnk, 1);
	for (int i = 1, uu, vv, ww; dif(i, limm); ++i) {
		cin >> uu >> vv >> ww;
		edge.insert({uu, vv, ww});
	}
	for (int i = 1; dif(i, limk); ++i) {
		cin >> node[i];
		for (int j = 1, ww; dif(j, limn); ++j) {
			cin >> ww;
			more[i].push_back({i + n, j, ww});
		}
	}
	edgeSieve();
	int maxt = 1 << k;
	for (int t = 1; dif(t, maxt); ++t)
		solve(t);
	cout << ans;
	return 0;
}