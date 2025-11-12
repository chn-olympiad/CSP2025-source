#include<bits/stdc++.h>
using namespace std;
struct node{
	int vi,wi;
};
vector<node>a[1000005];
bool vis[100005];
long long mnn=1e9;
int n,m,k;
void dfs(int x,int tp,long long fp){
	if(tp==n){
		mnn=min(mnn,fp);
	}
	for(auto i:a[x]){
		if(vis[i.vi]==0){
			vis[i.vi]=1;
			dfs(i.vi,tp+1,fp+i.wi);
			vis[i.vi]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(node{v,w});
		a[v].push_back(node{u,w});
	}
	for(int i=1;i<=k;i++){
		int u,w;
		cin>>u;
		for(int j=1;j<=n;j++){
			cin>>w;
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i,0,0);
	}
	cout<<mnn;
	return 0;
}
