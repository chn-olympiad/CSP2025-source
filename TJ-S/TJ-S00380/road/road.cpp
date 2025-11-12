#include<bits/stdc++.h>
#define N 10005
#define M 1000005
#define K 11
using namespace std;
struct e{
    int v,w;
    bool operator< (e a) const{
    	return w>a.w;
	}
};
vector<e> E[N];
priority_queue<e> q;
int n,m,k,u[M],v[M],w[M],c[K],a[K][N],ans;
vector<int> id[N];
int vis[N];
void kruskal(int x){
	vis[x]=true;
	for(auto y:E[x]) q.push(y);
	while(vis[q.top().v]&&!q.empty()) q.pop();
	if(!q.empty()){
		ans+=q.top().w;
		kruskal(q.top().v);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		e node;node.v=v[i];node.w=w[i];
		E[u[i]].emplace_back(node);
		node.v=u[i];
		E[v[i]].emplace_back(node);
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				id[i].emplace_back(j);
			} 
		}
		bool f=true;
		for(auto tmp:id[i]){
			f=false;
			break;
		}
		if(f) flag=false;
	}
	if(flag) for(int i=1;i<=k;i++){
		for(auto nid:id[i])
		for(int j=1;j<=n&&j!=nid;j++){
			e node;node.v=j;node.w=a[i][j];
			E[nid].emplace_back(node);
			node.v=nid;
			E[j].emplace_back(node);
		}
	}
	kruskal(1);
	cout<<ans<<endl;
	return 0;
}
