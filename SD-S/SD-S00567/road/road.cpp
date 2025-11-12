#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e4+1;
struct Edge {
	int u,v,w;
};
int n,m,k;
ll ans;
vector<Edge> edges;
vector<int> adj[N];
bool visited[N];
//特殊性质相当于在m条边里挑，满足包含从一头开始，能跑满n个顶点的若干条边 的边权和的最小值
//vector<Edge> path;
//inline bool judge() {
//	int cnt=0;
//	memset(visited,0,sizeof visited);
//	for(int i=1; i<=n; i++)
//		adj[i].clear() ;
//	for(int i=0; i<path.size(); i++) {
//		adj[path[0].u].push_back(path[0].v);
//		adj[path[0].v].push_back(path[0].u);
//	}
//	queue<int> q;
//	q.push(path.front().u) ;
//	while(!q.empty()) {
//		int top=q.front() ;
//		q.pop();
//		for(auto i:adj[top]) {
//
//			if(visited[i]==0) {
//				q.push(i);
//				visited[i]=1;
//				cnt++;
//			}
//		}
//	}
//	return cnt==n;
//}
//void dfs(int restM,int num,ll w) {
//	if(num==edges.size() ) {
//		if(restM==0) {
//			if(judge()) {
//				ans=min(ans,w);
//			}
//		}
//		return ;
//	}
//	if(restM-1>=0) {
//		path.push_back(edges[num]);
//		dfs(restM-1,num+1,w+edges[num].w);
//		path.pop_back();
//	}
//	dfs(restM,num+1,w);
//}
int vv[N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	ans=0;
	
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		vv[i]=w;
	//	edges.push_back({u,v,w}) ;
		
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n+1; j++) {
			int temp;
			cin>>temp;
		}
	}
	sort(vv+1,vv+n+1);
//	for(int i=n-1; i<=m; i++) {
//		//枚举边数
//		dfs(i,0,0);
//	}
//	cout<<ans<<endl;
	for(int i=1; i<=n-1; i++) {
		ans+=vv[i];
	}
	cout<<ans<<endl;
	return 0;
}

