#include<bits/stdc++.h>
#define endl "\n"
#define int long long 
#define PII pair<int,int>
using namespace std;
const int maxN=1e4+10,INF=INT_MAX;
struct node{int first,second,id;};
vector<node> g[maxN];
priority_queue<PII>pq;
int m,k,n,a[20][maxN],dis[maxN],ans=INF,f[maxN],vis[maxN],ww[maxN];
int dij(int h,int s){
	pq.push({0,s});
	for(int i=1;i<=n+h;i++)dis[i]=INF,vis[i]=0;
	dis[s]=0;
	int res=0;
	while(pq.size()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u]){
			int d=e.second,v=e.first,id=e.id;
			if(vis[v])continue;
			if(d+dis[u]<dis[v]){
				dis[v]=dis[u]+d;
				pq.push({dis[v],v});
				res+=ww[id];
				//cout<<res<<endl;
			}
		}
	}
	//cout<<"???????"<<endl;
	for(int i=1;i<=n+h;i++){
		//cout<<dis[i]<<' ';
		if(dis[i]==INF&&i<=n)return INF;
	}
	//cout<<endl;
	return res;
}
void solve(){
	int h=0,s=0;
	for(int i=1;i<=k;i++){
		if(f[i]){
			h++,s+=a[i][0];
			for(int j=1;j<=n;j++){
				int id=m+(h-1)*n+j;
				g[h+n].push_back({j,a[i][j],id});
				g[j].push_back({h+n,a[i][j],id});
				//cout<<"!"<<endl;
				ww[id]=a[i][j];
			} 
		}
	}
	ans=min(ans,dij(h,n+h)+s);
	for(int i=1;i<=k;i++){
		if(f[i]){
			for(int j=1;j<=n;j++){
				g[h+n].pop_back();
				g[j].pop_back();
			} 
		}
	}
}
void dfs(int x){
	if(x>k){
//		for(int i=1;i<=k;i++) cout<<f[i]<<' ';
//		cout<<endl;
		solve();
		return;
	}
	dfs(x+1);
	f[x]=1;
	dfs(x+1);
	f[x]=0;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		ww[i]=w;
		g[u].push_back({v,w,i});
		g[v].push_back({u,w,i});
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++) cin>>a[i][j];	
	dfs(1);
	cout<<ans;
	return 0;
}//Ren5Jie4Di4Ling5%
