#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 10005;
ll n,m,k,ans = 1e10,dis[1005][1005];
bool vis[maxn],vi[maxn][maxn];
struct edge{
	ll v,w;
};
struct cmp{
	bool operator()(edge & a,edge & b){
		return a.w > b.w;
	}
};
priority_queue<edge,vector<edge>,cmp>q[maxn];
void prim(ll cc){
	ll now = 0;
	bool usec = 0;
	for (int i = 1;i <= n;i++)while(!q[i].empty())q[i].pop();
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			if (dis[i][j])q[i].push({j,dis[i][j]});
		}
	}
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	for (int i = 1;i < n;i++){
		ll mins = 1e9,mini = 0;
		for (int j = 1;j <= n;j++){
			if (!vis[j])continue;
			while(!q[j].empty() && vis[q[j].top().v])q[j].pop();
			if (q[j].empty() || q[j].top().w > mins)continue;
			mins = q[j].top().w;
			mini = j;
		}
		if (vi[mini][q[mini].top().v])usec = 1;
		now += mins;
		vis[q[mini].top().v] = 1;
		q[mini].pop();
	}
	if (usec) ans = min(ans,now + cc);
	else ans = min(ans,now);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		ll u,v,w;
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	prim(0);
	//cout << ans << "\n";
	for (int i = 1;i <= k;i++){
		ll c,ds[maxn];
		cin >> c;
		memset(vi,0,sizeof(vi));
		for (int j = 1;j <= n;j++)cin >> ds[j];
		for (int j = 1;j <= n;j++){
			for (int h = 1;h <= n;h++){
				if (dis[j][h] && dis[j][h] > ds[j] + ds[h]){
					dis[j][h] = min(dis[j][h],ds[j] + ds[h]);
					vi[j][h] = 1;
				}
				else if (!dis[j][h]){
					dis[j][h] = ds[j] + ds[h];
					vi[j][h] = 1;
				}
			}
		}
		prim(c);
	}
	cout << ans << flush;
	return 0;
}

