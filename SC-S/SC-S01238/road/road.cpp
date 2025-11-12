#include <bits/stdc++.h>
using namespace std;

int n, m, k, c[50], a[12][10004];
int f[2000006], now_cnt = 0, flag=  0;

long long final_ans = 1000000000000000000;

struct edge {
	int u, v, w, flag = -1;
};

vector <edge> et;

vector <edge> e;

bool cmp (edge a, edge b) {
	return a.w < b.w;
}

int getfa(int x) {
	if (x == f[x]) return x;
	else {
		f[x] = getfa(f[x]);
		return f[x];
	}
}

bool vis[20];

void merge(int x, int y) {
	if (f[x] == x && f[y] == y) f[y] = x;
	else {
		if (f[x] == x) f[x] = y;
		else f[y] = x;
	}
}

long long Kruskal () {
	long long result = 0;
	for (int idx = 0;idx < e.size(); ++ idx) {
		edge ed = e[idx];
		int x = getfa(ed.u), y = getfa(ed.v);
		if (f[x] != f[y]) {
			result += ed.w;
			f[getfa(x)] = f[getfa(y)];
			now_cnt--;
		}
		if (now_cnt <= 0) return result;
		
	}
	
	 return result;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	flag = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge ed;
		ed.u = u; ed.v = v;
	
		
		ed.w = w;
		et.push_back(ed);
	}

	sort(et.begin(), et.end(), cmp);
	
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		if (c[i] != 0) flag = 1;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] != 0) flag = 1;
		}
	}
	
	if (flag){
		int h = (1 << k)- 1;
		while (h >= 0) {
			now_cnt = n;
			e = et;
			int t = h, idx = 1;
			long long ans = 0;
			while (t > 0) {
				if (t & 1) {
					now_cnt ++;
					ans += c[idx];
					for (int i = 1; i <= n; ++i) {
						edge ed;
						ed.u = n + idx;
						ed.v = i;
						ed.w = a[idx][i];
						ed.flag = idx;
						e.push_back(ed);
					}
				} t >>= 1; ++idx;
			}
			for (int i = 1;i <= n + 15; ++i) f[i] = i; 
			ans += Kruskal();
			final_ans = min(final_ans, ans);
--h;
		} cout << final_ans;
	
	} else {
		cout << 0;
	}
	return 0;
}