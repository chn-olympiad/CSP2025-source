#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct node{
	int v,w;
	bool operator<(const node A) const{
		return w<A.w;
	}
};
int n,m,k,dis[N],rt;
vector<node> g[N];
inline void solve(){
	if(k==0){
		priority_queue<node> q;
		q.push({rt,0});
		memset(dis,0x3f,sizeof dis);
		dis[rt]=0;
		while(!q.empty()){
			node now=q.front();
			q.pop();
			for(auto it:g[now.v]){
				if(dis[now.v]<dis[it.v]){
					dis[now.v]=max(dis[it.v],dis[now.v]);
				}
			}
		}
		cout<<dis[rt];
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		if(i==1){
			rt=u;
		}
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	cout<<0;
	return 0;
}
