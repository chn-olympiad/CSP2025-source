#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10, inf = 0x3f3f3f3f;


struct Edge{
	long long from, to, w;
	long long next;
}edge[M];

long long n, m, k;
long long head[N], tot = 0, dis[N];
long long a[10][N];

void init(){
	for (int i = 1; i <= n; i++) head[i] = -1, dis[i] = inf;
	for (int i = 1; i <= m; i++) edge[i].next = - 1;
}

void add(long long from, long long to, long long w){
	edge[++tot] = {from, to, w, head[from]};
	head[from] = tot;
}

int vis[N];
long long ans = 0;

queue <int> q;
void krul(long long p){
	q.push(p);
	dis[p] = 0;
	vis[p] = 1;
	while(!q.empty() ){
		int u = q.front(); q.pop();
		for (int i = head[u]; ~i; i = edge[i].next){
			long long v = edge[i].to, w = edge[i].w;
			if (!vis[v]){
				if (!q.empty()){
					int temp = q.front();	
					if (w + dis[u] < dis[temp]){
						dis[v] = dis[u] + w;
						q.pop();
						vis[temp] = 0;
						q.push(v);
						ans = dis[v];
					}
				}else{
					q.push(v);
					dis[v] = dis[u] + w;
					ans = dis[v];
				}
				
			}
		}
		vis[u] = 1;
	}
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	init();
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; i++){
		int u, v, w; cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			cin >> a[i][j];
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			for (int g = i + 1; g <= n; g++){
				add(i, g, a[j][i] + a[j][0] + a[j][g]);
				add(g, i, a[j][i] + a[j][0] + a[j][g]);
			}
		}
	}
	
	krul(1);
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}