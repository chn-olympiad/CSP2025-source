#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
using ll=long long;
const int N=1e4+51;
struct edge{
	int u,v,val;
};
unsigned int n,m,k;ll w[15], ans;
vector<unsigned int> g[N];
bitset<N> vis,_0;
edge eg[1000005];
//void dij(int st){
//	vector<ll> dist(n+k+5,1e18);
//	vector<int> vis(n+5,0);
//	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
//	q.push({0,st});
//	dist[st]=0;
//	while(q.size()){
//		pair<int,int> t=q.top();
//		q.pop();
//		if(vis[t.second]){
//			continue;
//		}
//		vis[t.second]=1;
//		for(pair<int,int> e:g[t.second]){
//			int v=e.first,val=e.second;
//			if(v<=n){
//				if(dist[v]>val+t.second){
//					dist[v]=val+t.second;
//					q.push({dist[v],v});
//				}
//			}
//		}
//	}
//	
//}
bool wolk(unsigned now){
	if(vis.count()==n){
		return 1;
	}
	vis[now]=1;
	bool f=0;
	for(auto x:g[now]){
		if(!vis[x]){
			if(wolk(x))f=1;
		}
	}
	return f;
}
void dfs(unsigned now,ll num){
	if(now==m+1){
		if(wolk(1)){
			ans=min(ans,num);
		}
		return ;
	}
	if(num>ans)return ;
	g[eg[now].u].push_back(eg[now].v);
	g[eg[now].v].push_back(eg[now].u);
	dfs(now+1,num+eg[now].val);
	g[eg[now].u].pop_back();
	g[eg[now].v].pop_back();
	dfs(now+1,num);
}
int main(){
	fre("road");
	cin>>n>>m>>k;
	for(unsigned int i=1;i<=m;i++){
//		int u,v,val;
		cin>>eg[i].u>>eg[i].v>>eg[i].val;
//		g[u].push_back({v,val});
//		g[v].push_back({u,val});
	}
//	for(unsigned int i=1;i<=k;i++){
//		cin>>w[i];
//		for(unsigned int j=1;j<=n;j++){
//			int val;
//			cin>>val;
//			g[n+i].push_back({j,val});
//			g[j].push_back({n+i,val});
//		}
//	}
	dfs(1,0);
	cout<<ans;
	return 0;
}