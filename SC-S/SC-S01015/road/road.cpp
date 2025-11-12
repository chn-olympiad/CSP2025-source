#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
struct mp{
	vector<int> to,v;
}a[N];
struct con{
	vector<int>v;
	int c;
}c[N];
bool vis[N];
int ans=0;
void dfs(int n){
	vis[n]=1;
	for(int i=1;i<=a[n].to.size();i++){
		if(!vis[i]){
			ans+=a[n].v[i];
			dfs(i);
		}
	}
}
int main(){
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].to.push_back(v);
		a[u].v.push_back(w);
		a[v].to.push_back(u);
		a[v].v.push_back(w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].c;
		for(int j=1;j<=n+1;j++){
			int x;
			cin>>x;
			c[i].v.push_back(x);
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}