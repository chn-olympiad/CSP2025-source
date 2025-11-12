#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
struct node{
	ll u,v,w;
	bool operator < (const node &x) const {return x.w<w;}
};
ll n,m,k;
vector<node>G[N];
ll pr(){
	vector<bool> vis(n+1,0);
	ll c=0,num=0;
	priority_queue<node>Q;
	Q.push({1,0,0});
	while(Q.size()){
		node tp=Q.top(); Q.pop();
		if(vis[tp.u]) continue;
		//cout<<tp.u<<' '<<tp.v<<' '<<tp.w<<' '<<vis[tp.u]<<'\n';
		vis[tp.u]=1;
		c++;
		num+=tp.w;
		if(c==n) return num;
		for(int i=0;i<G[tp.u].size();i++){
			node nw=G[tp.u][i];
			//cout<<"\\\\"<<tp.u<<' '<<tp.v<<' '<<tp.w<<'\n';
			if(vis[nw.v]==0) Q.push({nw.v,0,nw.w});
		}
	}
	//cout<<num<<' '<<c<<'\n';
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		G[u].push_back({u,v,w});G[v].push_back({v,u,w});
	}
	if(k==0){
		cout<<pr()<<'\n';
		return 0;
	}
	return 0;
}
