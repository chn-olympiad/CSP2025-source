#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/priority_queue.hpp>
#include <queue>
namespace Use {
	using std::sort;
	using std::queue;
	using std::bitset;
	using __gnu_pbds::priority_queue;
	using std::min;
}
using namespace Use;
typedef long long ll;
typedef double lf;
const int maxn = 1e5 + 10, maxm = 4e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct Vertex {
	int num;
	ll dis;
	bool operator <(const Vertex &b) const & { return dis > b.dis; }
};

struct Edge {
	int to;
	ll dis, cap, flow;
	int next;
} edge[maxm << 1];

int head[maxn], len = 1;
void insert(const int &u, const int &v, const ll &w, const ll &c, const ll &f = 0) {
	edge[++len] = {v, w, c, f, head[u]}, head[u] = len;
}

void emplace(const int &u, const int &v, const ll &w, const ll &c) {
	insert(u, v, w, c), insert(v, u, -w, 0);
}

bitset<maxn> vis;
ll w[maxn], reply;
int s, t;
queue<int> q;
void Bellman_Ford() {
	memset(w, 63, sizeof w), w[s] = 0, q = queue<int>(), q.push(s), vis[s] = 1;
	for (int u, v; !q.empty(); ) {
		u = q.front(), q.pop(), vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].next) {
			v = edge[i].to;
			if (edge[i].cap > edge[i].flow && w[v] > w[u] + edge[i].dis)
				w[v] = w[u] + edge[i].dis, vis[v] || (q.push(v), vis[v] = 1);
		}
	}
}

ll dis[maxn];
priority_queue<Vertex> h;
bool Dijkstra() {
	memset(dis, 63, sizeof dis), h.push({s, dis[s] = 0});
	ll d;
	for (int u, v; !h.empty(); ) {
		u = h.top().num, h.pop();
		for (int i = head[u]; i; i = edge[i].next) {
			v = edge[i].to;
			if (edge[i].cap > edge[i].flow && dis[v] > (d = dis[u] + edge[i].dis + w[u] - w[v]))
				h.push({v, dis[v] = d});
		}
	}
	return dis[t] != inf;
}

int cur[maxn];
ll DFS(const int &u, const ll &flow) {
	if (u == t || !flow) return flow;
	ll ans = 0, d;
	vis[u] = 1;
	for (int &i = cur[u], v; i; i = edge[i].next) {
		v = edge[i].to;
		if (!vis[v] && dis[v] == dis[u] + edge[i].dis + w[u] - w[v] && (d = DFS(v, min(flow - ans, edge[i].cap - edge[i].flow)))) {
			edge[i].flow += d, edge[i ^ 1].flow -= d, reply += d * edge[i].dis;
			if ((ans += d) == flow) break;
		}
	}
	return vis[u] = 0, ans;
}

void Init() { for (int i = 0; i < maxn; ++i) w[i] += dis[i]; }

ll Dinic() {
	ll flow = reply = 0;
	for (Bellman_Ford(); Dijkstra(); memcpy(cur, head, sizeof cur), vis.reset(), flow += DFS(s, inf), Init()) ;
	return flow;
}

int T, n, a[maxn][4];
bool A;
ll aA[maxn];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	for (; T; --T) {
		memset(head, 0, sizeof head), len = 1;
		s = 0;
		A = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= 3; ++j) scanf("%d", a[i] + j), A = j == 2 || j == 3 ? (A && !a[i][j]) : A;
		if (A) {
			reply = 0;
			for (int i = 1; i <= n; ++i) aA[i] = a[i][1];
			sort(aA + 1, aA + n + 1);
			for (int i = n / 2 + 1; i <= n; ++i) reply += aA[i];
			printf("%lld\n", reply);
		} else {
			for (int i = 1; i <= n; ++i) {
				emplace(s, i, -0, 1);
				for (int j = 1; j <= 3; ++j)
					emplace(i, n + j, -a[i][j], 1);
			}
			t = n + 4;
			for (int j = 1; j <= 3; ++j) emplace(n + j, t, -0, n / 2);
			Dinic(), printf("%lld\n", -reply);			
		}
	}
	return 0;
}