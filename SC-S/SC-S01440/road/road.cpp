#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int n,m,k;
vector<pair<int,int>> city[N];
struct Village {
	int re_build;
	vector<pair<int,int>> cost;
}v[15];

int bfs(int p,int q) {
	// init
	int dis[N];
	for(int i=1;i<=n;i++) {
		dis[i] = INT_MAX;
	}
	
	queue<pair<int,int>> que;
	que.push({1,0});
	while(!que.empty()) {
		int pos,dist;
		pos = que.front().first;
		dist = que.front().second;
		que.pop();
		
		for(auto p : city[pos]) {
			if(dist + p.second < dis[p.first]) {
				dis[p.first] = dist + p.second;
				que.push({p.first,dis[p.first]});
			}
		}
	}
	return dis[n];
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		city[u].push_back(make_pair(v,w));
		city[v].push_back(make_pair(u,w));
	} 
	bool cut = true;
	int mn=INT_MAX;
	for(int i=1;i<=k;++i) {
		cin>>v[i].re_build;
		mn = min(mn,v[i].re_build);
		for(int j=1;j<=n;++j) {
			int cost;
			cin>>cost;
			v[i].cost.push_back(make_pair(j,cost));
			if(cost != 0) cut = false;
		}
	}
	
	if(cut) {
		cout<<mn<<"\n";
		return 0;
	}
	
	if(k==0) {
		cout<<bfs(1,n);
	}
	return 0;
}