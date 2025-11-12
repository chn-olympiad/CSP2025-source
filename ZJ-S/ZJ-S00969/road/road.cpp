#include <bits/stdc++.h>

#define int long long

using namespace std;

int read() {
	int x = 0, y = 1; char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') y = -1;
		c = getchar();
	}
	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
	return x * y;
}

const int N = 1e4 + 100, M = 1e6 + 10;

int n, m, k, fa[N], c[11], ans;
struct edge {
	int u, v, w;
} e[M];
vector<edge> t[1030], a[11], tmp;

bool cmp(edge x, edge y) {
	return x.w < y.w;
}

int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void init() {
	for (int i = 1; i <= n + k; ++i) fa[i] = i; 
}

int lowbit(int x) {
	return x & -x;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; ++i) 
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	sort(e + 1, e + 1 + m, cmp);
	int sum = 0; init();
	for (int i = 1, j = 0; i <= m && j < n - 1; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int nu = find(u), nv = find(v);
		if(nu != nv) {
			sum += w;
			fa[nu] = nv;
			++j;
			t[0].push_back((edge){u, v, w});
		}
	}
	ans = sum;
	for (int i = 0; i < k; ++i) {
		c[i] = read();
		for (int j = 1; j <= n; ++j) {
			int x = read();
			a[i].push_back((edge){n + i + 1, j, x});
		}
		sort(a[i].begin(), a[i].end(), cmp);
	}
	for (int s = 1; s < 1 << k; ++s) {
		int sum = 0, cnt = 0;
		for (int j = 0; j < k; ++j) 
			if(s >> j & 1) sum += c[j], ++cnt;
		int ss = s ^ lowbit(s), pos = log2(lowbit(s));
		tmp.clear();
		int i = 0, j = 0;
		while(i < t[ss].size() && j < a[pos].size()) {
			if(t[ss][i].w < a[pos][j].w) 
				tmp.push_back(t[ss][i++]);
			else tmp.push_back(a[pos][j++]);
		}
		while(i < t[ss].size()) tmp.push_back(t[ss][i++]);
		while(j < a[pos].size()) tmp.push_back(a[pos][j++]);
		init();
		for (int i = 0, j = 0; i < tmp.size() && j < cnt + n - 1; ++i) {
			int u = tmp[i].u, v = tmp[i].v, w = tmp[i].w;
			int nu = find(u), nv = find(v);
			if(nu != nv) {
				sum += w;
				fa[nu] = nv;
				++j;
				t[s].push_back((edge){u, v, w});
			}
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}
