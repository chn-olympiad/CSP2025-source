#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define fst first
#define scd second
using namespace std;
const int N = 1e4 + 30;
const int INF = 0x3f3f3f3f3f3f3f3f;
vector<PII> e[N];
int ce[20][N];
int n, m, k, dis[N], ans = INF;
int vis[N];

void init(){
	for(int i=1;i<=n+k;i++){
		dis[i] = INF;
		vis[i] = 0;
	}
}

int Prim(int mark){
	priority_queue<PII, vector<PII>, greater<PII> > q;
	init();
	int ret = 0, cnt = 0, sumk = 0;
	dis[1] = 0;
	q.push({0, 1});
	for(int i=1;i<=k;i++){
		if(mark & (1ll<<i-1)) sumk++;
	}
	while(!q.empty()){
		if(cnt >= n + sumk) break;
		PII head = q.top();
		int u = head.scd, d = head.fst;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1, cnt++;
		ret += d;
		for(PII to : e[u]){
			int v = to.scd, w = to.fst;
			if(dis[v] <= w) continue;
			dis[v] = w;
			q.push({w, v});
		}
		if(u <= n){
			for(int i=1;i<=k;i++){
				if((mark & (1ll<<i-1)) == 0) continue;
				int v = n + i, w = ce[i][u];
				if(dis[v] <= w) continue;
				dis[v] = w;
				q.push({w, v});
			}
		}
		else if(u > n){
			for(int v=1;v<=n;v++){
				int w = ce[u-n][v];
				if(dis[v] <= w) continue;
				dis[v] = w;
				q.push({w, v});
			}
		}
	}
	return ret;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	int u, v, w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({w, v});
		e[v].push_back({w, u});
	}
	for(int i=1;i<=k;i++){
		cin>>ce[i][0];
		for(int j=1;j<=n;j++){
			cin>>ce[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++){
		int sum = Prim(i);
		for(int j=1;j<=k;j++){
			if(i & (1ll<<j-1)) sum += ce[j][0];
		}
		ans = min(ans, sum);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
