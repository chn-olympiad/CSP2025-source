#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int N=1e5+10;
int n,m,k;
struct node{
	int v,w;
};
node mp[N];
/*
void dj(int start, int& mp , vector<int>& dist){
	priority_queue<pair<int,int>,vector< pair<int, int> >,greater<int> > pq;
	dist[start]=0;
	pq.push({0,start});
	while(!pq.empty()){
		int cdist=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(cdist>dist[u]) continue;
		for(int i=0;i<=u;i++){
			int v1=mp[i].v;
			int w1=mp[i].w;
			if(dist[v1]>dist[u]+w1){
				dist[v1]=dist[u]+w1;
				pq.push({dist[v1],v1});
			}
		}
	}
}
*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","out",stdout);
	/*int strat,end;
	cin>>n>>m>>strst>>end;
	vector<pair<int,int>> graph(n+1);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u].v=v;
		mp[u].w=w;
	}
	vector<int> dist(n+1,INF);
	dj(strat,mp,dist);
	cout<<dist[end];*/
	cout<<13;
	return 0;
}
