#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
const long long inf=0x3f3f3f3f3f3f3f3f;

int n,m,k;
struct edge{
	int to;
	long long w;
};
vector<edge> g[N];
long long c[N][15];
long long cost[N];
bool vis[N],v[N];
long long ans;
struct node{
	int id;
	long long cost;
	bool operator <(const node &x)const{
		return cost>x.cost;
	}
};
priority_queue<node> q;

void pr(){
	
	memset(cost,inf,sizeof(cost));
	cost[1]=0;
	q.push({1,0});
	
	while(q.size()){
		node u=q.top();
		q.pop();
		if(vis[u.id]) continue;
		ans+=u.cost;
		vis[u.id]=true;
		for(int i=0;i<g[u.id].size();i++){
			edge v=g[u.id][i];
			if(cost[v.to]>v.w){
				cost[v.to]=v.w;
				q.push({v.to,cost[v.to]});
			}
		}
	}
	
}

int main (){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	long long x,y,w;
	for(int i=1;i<=m;i++){
		cin >> x >> y >> w;
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)
			cin >> c[i][j];
	}
	
	pr();
	
	cout << ans;
	
	return 0;
}
