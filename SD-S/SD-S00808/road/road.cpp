#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u,v,w,dis[20005],vis[20005],c[15],a[15][20005];
vector<pair<int,int>> e[20005];
int prim(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
	memset(dis,0x3f,sizeof dis);
	int ans=0,cnt=0;
	q.emplace(0,1);
	dis[1]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		cnt+=u<=n;
		ans+=dis[u];
		if(cnt==n){
			break;
		}
		vis[u]=1;
		for(auto i:e[u]){
			if(dis[i.first]>i.second){
				dis[i.first]=i.second;
				q.emplace(dis[i.first],i.first);
			}
		}
	}
	return ans;
}
void wrok(int x){
	int tmp=x,y=0;
	while(tmp){
		if(tmp&1){
			for(int i=1;i<=n;i++){
				e[y+n+1].emplace_back(i,a[y][i]);
				e[i].emplace_back(y+n+1,a[y][i]);
			}
		}
		y++;
		tmp>>=1;
	}
	prim();
	tmp=x;
	y=0;
	while(tmp){
		if(tmp&1){
			for(int i=1;i<=n;i++){
				e[y+n+1].pop_back();
				e[i].pop_back();
			}
		}
		y++;
		tmp>>=1;
	}
}
void slove(){
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<(1<<k)-1;i++){
		wrok(i);
	}
}
signed main(){
	ifstream cin("road.in");
	ofstream cout("road.out");
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	for(u=n+1;u<=n+1+k;u++){
		cin>>w;
		for(v=1;v<=n;v++){
			cin>>w;
			e[u].emplace_back(v,w);
			e[v].emplace_back(u,w);
		}
	} 
	cout<<prim();
	return 0;
} 
