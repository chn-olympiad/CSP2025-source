#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int Ac;
vector<vector<int>>roads;
vector<vector<int>>cous;
int S1() {
	vector<pair<int,pair<int,int> > >road;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(roads[i][j]!=-1)
				road.push_back({roads[i][j],{i,j}});
		}
	}
	sort(road.begin(),road.end());
	vector<bool>visited(n);
	int sum=0;
	for(int i=0; i<road.size(); i++) {
		auto u=road[i].second.first;
		auto v=road[i].second.second;
		if(!visited[u]||!visited[v]) {
			sum+=road[i].first;
			visited[u]=true;
			visited[v]=true;
		}
	}
	return sum;
}
int A() {
	vector<pair<int,pair<int,int> > >road;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int K=1; K<=k; K++) {
				if(roads[i][j]==-1)
					roads[i][j]=cous[K][i]+cous[K][j];
				else
					roads[i][j]=min(roads[i][j],cous[K][i]+cous[K][j]);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(roads[i][j]!=-1)
				road.push_back({roads[i][j],{i,j}});
		}
	}
	sort(road.begin(),road.end());
	vector<bool>visited(n);
	int sum=0;
	for(int i=0; i<road.size(); i++) {
		auto u=road[i].second.first;
		auto v=road[i].second.second;
		if(!visited[u]||!visited[v]) {
			sum+=road[i].first;
			visited[u]=true;
			visited[v]=true;
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	roads.resize(n+1);
	for(int i=0; i<=n; i++) roads[i].resize(n+1,-1);
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		roads[u][v]=w;
		roads[v][u]=w;
	}
	cous.resize(n+1);
	for(int i=1; i<=k; i++) cous[i].resize(n+1,-1);
	for(int i=1; i<=k; i++) {
		cin>>cous[i][0];
		Ac+=cous[i][0];
		for(int j=1; j<=n; j++) {
			cin>>cous[i][j];
		}
	}
	if(k==0) {
		cout<<S1()<<endl;
		return 0;
	}
	if(Ac==0) {
		cout<<A()<<endl;
		return 0;
	}
	return 0;
}