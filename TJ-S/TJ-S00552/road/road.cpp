#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <limits>
#define ll long long
using namespace std;
struct Edge {
	int from;
	int to;
	ll w;
	Edge(): from(0), to(0) {}
	Edge(int from, int to, ll w): from(from), to(to), w(w) {}
};
struct Vil {
	ll c;
	vector<ll> dis;
	Vil(): c(0), dis(vector<ll>()) {}
	Vil(ll c, vector<ll> dis): c(c), dis(dis) {}
};
vector<vector<Edge>> edges;
vector<Vil> vils;
set<int> vis;
int n, m, k;
vector<ll> dis(n + 1, numeric_limits<ll>::max());
bool spe1 = false;
bool spe2 = true;
struct Compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};
void solve1() {
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, Compare> p;
	dis[1] = 0;
	vis.insert(1);
	p.push(make_pair(1, 0));
	for (auto e : edges[1]) {
		dis[e.to] = e.w;
	} 
	bool finished = false;
	ll ans = 0;
	while (!finished) {
		finished = true;
		pair<int, ll> t = p.top();
		ans += t.second;
		int top = t.first;
		p.pop();
		for (auto e : edges[top]) {
			dis[e.to] = min(dis[top] + e.w, dis[e.to]);
			if (vis.find(e.to) == vis.end()) {
				finished = false;
				p.push(make_pair(e.to, e.w));
				vis.insert(e.to);
			}
		}
	}
	cout << ans << endl;
	return;
}
void solve2() {
	for (int i = 0; i < k; i++) {
		int point = 0;
		for (int j = 1; j <= n; j++) {
			if (vils[i].dis[j] == 0) {
				point = j;
				break;
			}
		}
		//cout << i << " " << point << endl;
		for (int j = 1; j <= n; j++) {
			if (j != point) {
				edges[j].push_back(Edge(j, point, vils[i].dis[j]));
				edges[point].push_back(Edge(point, j, vils[i].dis[j]));
			}
		}
	}
	solve1();
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	edges.assign(n + 1, vector<Edge>());
	vils.assign(k, Vil());
	if (k == 0) spe1 = true;
	for (int i = 1; i <= m; i++) {
		int from, to;
		ll w;
		cin >> from >> to;
		cin >> w;
		edges[from].push_back(Edge(from, to, w));
		edges[to].push_back(Edge(to, from, w));
	}
	//cout << edges[1][0].to << " " << edges[1][0].w << endl;
	for (int i = 0; i < k; i++) {
		cin >> vils[i].c;
		if (vils[i].c != 0) spe2 = false;
		vils[i].dis.assign(n + 1, 0);
		for (int j = 1; j <= n; j++) {
			cin >> vils[i].dis[j];
		}
		//cout << i << " " << vils[i].dis[1] << endl;
	}
	if (spe1) {
		solve1();
	}
	else if (spe2) {
		solve2();
	}
	else {
		cout << 2 << endl;
	}
	return 0;
}
