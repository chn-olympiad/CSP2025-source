/*
写不完了,正解是O(2^k*nlogn)的
我们二进制枚举一下每个村庄是否重建
然后加入边直接跑kruscal 
洛谷号:love_luogu 
*/
#include<bits/stdc++.h> 
#define ll long long
#define pb push_back
#define in insert
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int N = 1e4 + 25;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct edge{
	int v;
	ll w;
	bool operator<(const edge &x)const{
		return w < x.w;
	}
};
ll dis[N];
vector<edge>g[N];
struct node{
	int id;
	ll we;
}w[N];
int n,m,k;
int c[N];
bool vis[N];
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	priority_queue<edge>q;
	q.push({1,0});
//	vis[1] = 1;
	while(!q.empty()){
		int u = q.top().v;
		q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(auto it:g[u]){
			int v = it.v,w = it.w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push({v,dis[v]});
			}
		}
	}
}
bool cmp1(node x,node y){
	return x.we < y.we;
}
bool cmp(node x,node y){
	return x.id < y.id;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;++i){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	for(int i = 1;i <= k;++i){
		int u = i + n;
		cin>>c[i + n];
		for(int j = 1;j <= n;++j){
			int v = j;
			cin>>w[j].we;
//			cout<<u<<" "<<v<<" "<<w[i].we<<'\n';
			w[j].id = j;
		}
		sort(w + 1,w + 1 + n,cmp1);
		w[1].we += c[u];
		sort(w + 1,w + 1 + n,cmp);
//		for(int )
		for(int j = 1;j <= n;++j){
			int v = j;
//			cout<<u<<" "<<v<<" "<<w[j].we<<'\n';
			g[u].pb({v,w[j].we});
			g[v].pb({u,w[j].we});
		}
	}
	dijkstra();
	ll ans = 0;
	for(int i = 1;i <= n;++i){
		ans = max(ans,dis[i]);
	}
	cout<<ans<<'\n';
}
