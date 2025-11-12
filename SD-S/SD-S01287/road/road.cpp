#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
const int maxm = 1e6 + 10;

int n, m, k;
int c[15], a[15][maxn];
vector<int> adj[maxm];
struct Edge{
	int u, v, w;
	bool operator<(const Edge& tmp)const{
		return w < tmp.w;
	}
}edge[maxm];

int ans, tot;
Edge g[maxm];

struct DSU{
	int fa[maxn];
	void init(){
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int find(int x){
		if (x == fa[x]) return x;
		else return fa[x] = find(fa[x]);
	}
}dsu;

void kruskal(){
	dsu.init();
	sort(edge + 1, edge + 1 + m);
	
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int fx = dsu.find(edge[i].u);
		int fy = dsu.find(edge[i].v);
		if (fx == fy) continue;
		g[++tot] = {edge[i].u, edge[i].v, edge[i].w};
		dsu.fa[fx] = fy;
		ans += edge[i].w;
		cnt++;
		if (cnt == n-1) break;
	}
}

bool vis[1010][1010] = {false};

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		adj[edge[i].u].push_back(edge[i].v);
		adj[edge[i].v].push_back(edge[i].u);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	kruskal();
	
	for (int i = 1; i <= k; i++) {
		int res = ans + c[i];
		for (int j = 1; j <= tot; j++) {
			int u = g[j].u, v = g[j].v;
			//1:连u和v
			int res1 = a[i][u] + a[i][v];
			//2:连u和v的临界点
			int res2 = 0;
			int minu = 0x3f3f3f3f, minv = 0x3f3f3f3f;
			for (int k = 0; k < adj[v].size(); k++) {
				minv = min(minv, a[i][adj[v][k]]);
			}
			res2 = a[i][u] + minv;
			//3:连u的临界点和v
			int res3 = 0;
			minu = 0x3f3f3f3f, minv = 0x3f3f3f3f;
			for (int k = 0; k < adj[u].size(); k++) {
				minu = min(minu, a[i][adj[u][k]]);
			}
			res3 = a[i][v] + minu;
			//4:连u的临界点和v的临界点 
			int res4 = 0;
			minu = 0x3f3f3f3f, minv = 0x3f3f3f3f;
			for (int k = 0; k < adj[u].size(); k++) {
				minu = min(minu, a[i][adj[u][k]]);
			}
			for (int k = 0; k < adj[v].size(); k++) {
				minv = min(minv, a[i][adj[v][k]]);
			}
			res4 = minu + minv;
			
//			cout << u << " " << v << " " << g[j].w << " " << res1 << " " << res2 << " " << res3 << " " << res4 << "\n";
			
			res -= g[j].w;
			res += min(res1, min(res2, min(res3, res4)));
			
			if (res < ans) {
				ans = res;
				break;
			}
		}
	}
	
	printf("%d\n", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
