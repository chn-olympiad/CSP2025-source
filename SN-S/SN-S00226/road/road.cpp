// 张思晨-SN-S00226-西安滨河学校 
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e4 + 100;
const int M = 2e6 + 100;
int n, m, k;
struct rode {
	int u;
	int v;
	int w;
}Rode[M];
int cnt = 0;
int c[15];
int a[15][N];
int x, y, z;
bool cmp(rode r1, rode r2) {
	return r1.w < r2.w;
}
int ans = 0;
int f[N];
int find(int x) {
	if (f[x] == x)
		return x;
	f[x] = find(f[x]);
	return f[x];
}

inline void addedge(int q, int t, int o) {
	Rode[cnt].u = q;
	Rode[cnt].v = t;
	Rode[cnt++].w = o;
	return;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> z;
		Rode[cnt].u = x;
		Rode[cnt].v = y;
		Rode[cnt++].w = z;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
		if (c[i] == 0) {
			int mp;
			for (int j = 1; j <= n; ++j) {
				if (a[i][j] == 0) {
					mp = j;
				}
			}
			for (int j = 1; j <= n; ++j) {
				addedge(mp, j, a[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
	}
	sort(Rode, Rode + cnt, cmp);
	for (int i = 0; i != cnt; ++i) {
		//cout << Rode[i].u << ' ' << Rode[i].v << ' ' << Rode[i].w << '\n';
		int fir = Rode[i].u, sec = Rode[i].v;
		int cos = Rode[i].w;
		int F = find(fir);
		int S = find(sec);
		if (F == S)
			continue;
		f[S] = F;
		ans += cos;
	}
		
	cout << ans << endl;
	
	return 0;
}
