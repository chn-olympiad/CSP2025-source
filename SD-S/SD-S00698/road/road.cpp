#include<iostream>
#include<cstring>
#include<queue>
#include <stack>
#include <vector>
using namespace std;
const int N =10021,M=1000001;
vector<pair<int,int>> graph[N];
int n,m,k;
queue<int> pq;
long long dist[N][N];
bool inQueue[N];
void spfa(int start){
	
	pq.push(start);
	dist[start][start] = 0;
	for(;!pq.empty();){
		int u = pq.front();
		//cout << u << endl;
		pq.pop();
		inQueue[u] = false;
		for(auto v: graph[u]){
			//cout << v.first  << endl;
			if(dist[start][v.first]>dist[start][u]+v.second){
				dist[start][v.first] = dist[start][u]+v.second;
				if(!inQueue[v.first]){
					pq.push(v.first);
					
				}
			}
		}
	}
}

long long ans= 0;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	for(int j=n+1;j<=n+k+1;j++){
		int price=0;
		scanf("%d",&price);
		for(int i=1;i<=n;i++){
			int w;
			scanf("%d",&w);
			graph[i].push_back({j,w+price});
			graph[j].push_back({i,w+price});
		}
	}
	for(int i=1;i<=n;i++) spfa(i);
	long long ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout << dist[i][j] << endl;
			ans=max(ans,dist[i][j]);
		}
	}
	cout << ans;
	return 0;
}

