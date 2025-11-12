#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define per(i, l, r) for (int i = (int)(r); i >= (int)(l); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
using i64 = long long;
#define int i64
const int maxn = 10050, mod = 998244353;
int n, m, k;
int a[12][maxn], c[20];
vector<pair<int, int>> e[maxn], e1[maxn];
int vis[maxn];
void Pr() {
	rep(i, 1, n) {
		vis[i] = 0;
	}
	priority_queue<pair<int, pair<int, int>>> q;
	q.push({0, {1, 0}});
	int res = 0, cnt = 0;
	while (q.size()) {
		pair<int, pair<int, int>> u = q.top();
		if (vis[u.second.first]) {
			q.pop();
			continue;
		}
		cnt++;
		if (u.second.first != 1) {
			e[u.second.first].push_back({u.second.second, -u.first});
			e[u.second.second].push_back({u.second.first, -u.first});
//			cout << u.second.first << " " << u.second.second << " " << -u.first << "\n";
		}
		if (cnt == n) {
			return;
		}
		q.pop();
		vis[u.second.first] = 1;
		for (pair<int, int> _ : e1[u.second.first]) {
			int v = _.first, w = _.second;
			q.push({-w, {v, u.second.first}});
		}
	}
} 
int Prim(int p) {//对当前图做最小生成树 
	rep(i, 1, n + k) {
		vis[i] = 0;
	}
	priority_queue<pair<int, int>> q;
	q.push({0, 1});
	int res = 0, cnt = 0;
	while (q.size()) {
		int u = q.top().second;
		if (vis[u]) {
			q.pop();
			continue;
		}
		cnt++;
		res -= q.top().first;
		if (cnt == n + p) {
			return res;
		}
		q.pop();
		vis[u] = 1;
		for (pair<int, int> _ : e[u]) {
			int v = _.first, w = _.second;
			q.push({-w, v});
		}
	}
	return 1e17;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		e1[u].push_back({v, w});
		e1[v].push_back({u, w});
	}
	Pr(); 
	rep(i, 1, k) {
		cin >> c[i];
		rep(j, 1, n) {
			cin >> a[i][j];
		}
	}
	int ans = 1e17;
	rep(S, 0, (1 << k) - 1) {
		int now = 0, q = 0;
		rep(i, 1, k) {
			if (S & (1 << (i - 1))) {
				q++;
				rep(j, 1, n) {
					e[n + i].push_back({j, a[i][j]});
					e[j].push_back({n + i, a[i][j]});
				}
				now += c[i];
			}
		}
		int P = Prim(q);
		now += P;
		ans = min(ans, now);
		rep(i, 1, k) {
			if (S & (1 << (i - 1))) {
				rep(j, 1, n) {
					e[j].pop_back();
					e[n + i].pop_back();
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
} 
//T2
//类似一个求最小生成树，可以先枚举激活的点的编号，2^10，然后相当于是在这样的一个东西里面加入一些边然后跑prim 
//时间复杂度是大概 O(2^10*nlogm)更好的做法就只有B算法了，但是实在写不出来卡常就认了吧 
//不对不对，可以现在原图上跑出最小生成树，然后再来暴力，然后就对完了 

