#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,vis[10010],a[10010],yz[10010];
struct node{
	long long v,w;
};
vector<node>e[10010];
queue<node>q;
void bfs(int  g){
	vis[g]=1;
	q.push({g,0});
	while(!q.empty()){
		node p=q.front();
		q.pop();
		a[p.v]=p.w;
		for(int i=0;i<e[p.v].size();i++){
			if(!vis[e[p.v][i].v]||a[e[p.v][i].v]>=a[p.v]+e[p.v][i].w){
				q.push({e[p.v][i].v,a[p.v]+e[p.v][i].w});
				vis[e[p.v][i].v]=1;
				yz[e[p.v][i].v]=e[p.v][i].w;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int ua,va,wa;
		cin>>ua>>va>>wa;
		e[ua].push_back({va,wa}); 
		e[va].push_back({ua,wa});
	}
	bfs(1);
	for(int i=1;i<=n;i++){
		if(yz[i])ans+=yz[i];
	}
	cout<<ans;
	return 0;
}
