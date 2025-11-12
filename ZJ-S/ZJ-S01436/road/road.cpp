#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e4+3;

/*
road
- I have no idea about full marks. let's try ~35pts
-- That's so strange. The last pretest just can't pass.
Please, don't let it be 0pts
*/

int n, m, k;
bool zerocost = true;
int fa[N];
long long c[N];
long long recon[30][N];

int query(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = query(fa[x]);
}

inline void merge(int a, int b) {
	fa[query(a)] = query(b);
}

struct edge {
	int from, to;
	long long val;
	int condit;
	edge() {
		
	}
	edge(int from, int to, long long val, int condit = 0)
		: from(from), to(to), val(val), condit(condit) {
			
		}
};

vector<edge> edges;
//vector<edge> actedges;
//vector<edge> graph[N];
//vector<edge> actgraph[N];	// actual graph
// (in kruskal evaluation)

// Sort edges (not needed right away)
bool cmp(const edge &a, const edge &b) {
//	return a.to < b.to;
	return a.val < b.val;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	edges.reserve(m);
	for (int i = 0; i < m; i++) {
		int u,v;
		long long w;
		cin>>u>>v>>w;
		edges.push_back(edge(u,v,w));
//		graph[u].push_back(edge(v, w));
//		graph[v].push_back(edge(u, w));
	}
	
//	for (int i = 1; i <= n; i++) {
//		sort(graph[i].begin(), graph[i].end(), cmp);
//	}
	for (int i = 1; i <= k; i++) {
		cin>>c[i];
		for (int j = 1; j <= n; j++) cin>>recon[i][j];
	}
	
	// Maybe not so bad
	for (int j = 1; j <= k; j++) {
		for (int von = 1; von <= n; von++) {
			for (int nach = von+1; nach <= n; nach++) {
					long long besser = recon[j][von] + recon[j][nach];
					edges.push_back(edge(von, nach, besser, j));
			}
		}
		
	}
	sort(edges.begin(), edges.end(), cmp);
//	cerr << "Total edges: " << edges.size() << endl;
	long long ans = 8e18;	// infinity
	for (int plan = 0; plan < (1<<k); plan++) {
		long long cur = 0ll;
		for (int i = 0; i < k; i++) {
			if (plan&(1<<i)) cur += c[i+1];
		}
		/*
		for (auto &i : actedges) {
			for (int j = 1; j <= k; j++) {
				if (plan&(1<<(j-1))) {
					long long besser = recon[j][i.from] + recon[j][i.to];
					if (besser < i.val) {
						i.val = besser;
					}
				}
			}
		}*/
		// Run kru. Maybe too many sorts aren't needed.
//		sort(actedges.begin(), actedges.end(), cmp);
		for (int i = 1; i <= n; i++) fa[i] = i;
		int seledge = 0;
		for (auto &i : edges) {
			if (seledge >= (n-1)) break;
			if (i.condit && (!(plan & (1<<(i.condit-1))))) {
//				cerr << "CANNOT SELECT " << i.from << "--" << i.to << " at " << i.val << endl;
				
				continue;	
			}
			int qfrom = query(i.from);
			int qto = query(i.to);
			if (qfrom != qto) {
				fa[qfrom] = qto;
				cur += i.val;
//				cerr << "Selecting " << i.from << "--" << i.to << " at " << i.val << endl;
				seledge++;
			}
		}
		/*
		cerr << "--> Plan of selecting: ";
			for (int i = 1; i <= k; i++) {
				if (plan&(1<<(i-1))) cerr << i << ',';
			}
			cerr << " has " << cur << endl;
		*/
		if (cur < ans) {
			
			ans = cur;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}