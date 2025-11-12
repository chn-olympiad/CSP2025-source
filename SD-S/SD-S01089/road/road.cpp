#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int maxn=1e6+5;
int n,m,k;
vector<pair<int,int>> g[maxn];
int c[15];
bool A=true;
int dist[maxn];
bool vist[maxn];

//void dijkstra(int st){
//	memset(dist,0x3f,sizeof dist);
//	queue<pair<int,int>> q;
//	q.push({st,0});
//	dist[st]=0;
//	vist[st]=true;
//	while(!q.empty()){
//		pair<int,int> t=q.front();q.pop();
//		for(auto it:g[t.first]){
//			int i=it.first,j=it.second;
//			if(vist[i])continue;
//			vist[i]=true;
//			if(dist[i]>dist[t.first]+j){
//				dist[i]=dist[t.first]+j;
//			}
//			q.push({i,dist[i]});
//		}
//	}
//	return ;
//}

void bfs(int st){
	memset(vist,false,sizeof vist);
	queue<pair<int,int>> q;
	q.push({st,0});
	vist[st]=true;
	dist[st]=0;
	while(!q.empty()){
		auto t=q.front();q.pop();
		for(auto it:g[t.first]){
			int i=it.first,j=it.second;
			if(vist[i])continue;
			dist[i]=min(dist[t.first]+j,dist[i]);
			vist[i]=true;
			q.push({i,dist[i]});
		}
	}
	return ;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	if(k==0){
		int ans=1e18;
		for(int i=1;i<=n;i++){
			memset(dist,0x3f,sizeof dist);
			bfs(i);
			int temp=0;
			for(int i=1;i<=n;i++){
				temp+=dist[i];
			}
			ans=min(ans,temp);
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)A=false;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			if(A==true)g[i+n].push_back({j,w});
		}
	}
	if(A==true){
		int ans=1e18;
		for(int i=1;i<=n+k;i++){
			memset(dist,0x3f,sizeof dist);
			bfs(i);
			int temp=0;
			for(int i=1;i<=n;i++){
				temp+=dist[i];
			}
			ans=min(ans,temp);
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
/*
4 4 0
2 4 4
3 1 2
2 3 1
4 3 1


4 5 0
1 2 1
2 4 2
1 4 3
1 3 3
3 4 5

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4

*/
