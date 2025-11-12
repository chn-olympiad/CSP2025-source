#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+5;
const int mod=1e9+7;
int n,m,k,vis[mx],dis[1005],ans;
struct node{
	int v,w;
};
vector<node> q[mx];
void dij(int st){
	memset(dis,0x7f,sizeof dis);
	dis[st]=0;
	vis[st]=1;
	queue<int> dq;
	int l=0;
	dq.push(st);
	while(!dq.empty()){
		int u=dq.front();
		l=u;
		dq.pop();
		for(node v : q[u]){
			if(!vis[v.v]){
				vis[v.v]=1;
				dis[v.v]=min(dis[v.v],dis[u]+v.w);
				dq.push(v.v);
			}
		}
	}
	ans+=dis[l];
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q[u].push_back({v,w});
		q[v].push_back({u,w});
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(!vis[i])dij(i);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			q[i].push_back({j,0});
			q[j].push_back({i,0});
		}	
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])dij(i);
	}
	cout<<ans;
	return 0;
}