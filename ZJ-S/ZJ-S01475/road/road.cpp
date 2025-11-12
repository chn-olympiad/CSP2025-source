#include <bits/stdc++.h>
#define _for(i, x, y) for(int (i)=(x); (i)<=(y); ++i)
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 5;

struct edge {
	int v, w;
	
	edge(int _v=0, int _w=0) {
		v = _v;
		w = _w;
	}
	
	bool operator<(const edge &x) const {
		return w < x.w;
	}
};

int n, m, k;
multiset<edge> e[maxn];

int rem;
int color[maxn];
int cl = 0;


int ans = 0;

//struct raw_edge {
//	int u, v, w;
//	
//	raw_edge(int _u=0, int _v=0, int _w=0) {
//		u = _u, v = _v, w = _w;
//	}
//};

struct cross {
	int c1, c2, w;
	
	cross(int _c1=0, int _c2=0, int _w=0) {
		c1 = _c1, c2 = _c2, w = _w;
	}
	
	bool operator<(const cross &x) const {
		return w < x.w;
	}
};

void dfs(int x) {
	color[x] = cl;
	for (edge ed : e[x]) {
		int v=ed.v, w=ed.w;
		if (color[v]) continue;
		
		color[v] = cl;
		dfs(v);
	}
}

int ru[maxm], rv[maxm], rw[maxm];

map< pair<int, int>, set<int> > xed;

pair<int, int> mkp(int x, int y) {
	return make_pair(min(x, y), max(x, y));
}

vector<edge> ce[maxn];
set< pair<int, int> > all_clust;

struct node {
	int u, v, w;
	
	bool operator<(const node &x) const {
		return w < x.w;
	}
};

multiset<node> st;

int ffa[maxn];

int ffind(int x) {
	return x == ffa[x] ? x : ffa[x] = ffind(ffa[x]);
}

void mmerge(int x, int y) {
	auto fx = ffind(x);
	auto fy = ffind(y);
	if (fx != fy) {
		ffa[fx] = fy;
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	rem = n;
	_for (i, 1, n) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ru[i] = u;
		rv[i] = v;
		rw[i] = w;
		
		e[u].insert(edge(v, w));
		e[v].insert(edge(u, w));
	}
		
	_for (i, 1, m) {
		int c;
		scanf("%d", &c);
		
		int u = n+i;
		_for (j, 1, n) {
			int w;
			scanf("%d", &w);
			
			ru[u] = u;
			rv[u] = j;
			rw[u] = w;
			
			e[u].insert(edge(j, w));
			e[j].insert(edge(u, w));
		}
	}
	
	_for (i, 1, n) {
		if (!color[i]) {
			++cl;
			dfs(i);
		}
	}
	
//	cout << "COLOR: \n";
	_for (i, 1, n) {
		color[i] = i;
//		cout << color[i] << endl;
	}

	_for (i, 1, m) {
//		cout << "hi";
//cout << color[ru[i]];
//cout << color[rv[i]];
		if (color[ru[i]] != color[rv[i]]) {
			pair<int, int> sd = mkp(color[ru[i]], color[rv[i]]);
			xed[sd].insert(rw[i]);
			all_clust.insert(sd);
		}
	}
	
	for (auto pr : all_clust) {
//		ce[pr.first].push_back(edge(pr.second, *xed[pr].begin()));
//		ce[pr.second].push_back(edge(pr.first, *xed[pr].begin()));
		
		st.insert((node){pr.first, pr.second, *xed[pr].begin()});
//		ffa[pr] = pr;
	}
	
	_for (i, 1, cl) {
		ffa[i] = i;
	}
	
	for (node nd : st) {
//		cout << nd.u << " " << nd.v << " " << nd.w << endl;
		if (ffind(nd.u) == ffind(nd.v)) continue;
		
		mmerge(nd.u, nd.v);
		ans += nd.w;
	}
	
	printf("%d\n", ans);
	return 0;
}
