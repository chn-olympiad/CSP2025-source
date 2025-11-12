#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>q[1234512];
int vis[1234512],dis[1234512];
int n,m,k,ans=INT_MAX;
int dij(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	int x,ans=INT_MAX;
	while(!vis[n]){
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<ans){
				x=i,ans=dis[i];
			}
		}
	}
	vis[x]=1;
	for(auto it:q[x]){
		int y=it.first();
		int z=it.second();
		if(dis[x]+z<dis[y]){
			dis[y]=dis[x]+z;
		}
	}
	if(dis[n]==0x3f3f3f3f) return -1;
	else return dis[n];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		q[u].push_back(v,w);
		q[v].push_back(u,w);
	}
	for(int i=1;i<=k;++i){
		int w,a[12345];
		cin>>w;
		for(int j=1;j<=n;++j){
			cin>>a[j];
			if(w==0){
				q[n+i].push_back(j,a[j]);
				q[n+i].push_back(j,a[j]);
			}
		} 
	}
	cout<<dij(); 
	return 0;
}//Ren5Jie4Di4Ling5%
