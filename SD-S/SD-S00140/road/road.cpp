#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+30;
int n,m,k;
ll c[15],trueans=1e17+10,con[N];
struct node{
	int v;
	ll w;
};
vector<node> vec[N],ve[10],newvec[N*5];
priority_queue<pair<ll,int> > pq;
bool vis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>con[j];
		for(int j=1;j<=n;j++){
			if(c[i]!=0){
				ve[i].push_back({j,con[j]});
			}else{
				for(int l=j+1;l<=n;l++){
					vec[j].push_back({l,con[j]+con[l]});
					vec[l].push_back({j,con[j]+con[l]});
				}
			}
		}
	}	
	for(int i=0;i<(1<<k);i++){
		ll ans=0;
		for(int j=1;j<=n;j++) newvec[j]=vec[j];
		for(int j=0;j<k;j++){
			if(c[j+1]==0&&(i>>j)&1==0) break;
			if((i>>j)&1==1){
				ans+=c[j+1];
				if(c[j+1]==0) continue;
				for(int l=0;l<ve[j+1].size();l++){
					int v=ve[j+1][l].v;
					ll w=ve[j+1][l].w;
					newvec[v].push_back({n+j+1,w});
					newvec[n+j+1].push_back({v,w});
				}
			}
		}
		while(!pq.empty()) pq.pop();
		memset(vis,0,sizeof vis);
		vis[1]=1;
		for(int j=0;j<newvec[1].size();j++){
			pq.push({-1*newvec[1][j].w,newvec[1][j].v});
		}
		while(!pq.empty()){
			ll dis=-1*pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			ans+=dis;
			for(int j=0;j<newvec[u].size();j++){
				ll w=newvec[u][j].w;
				ll v=newvec[u][j].v;
				if(!vis[v]){
					pq.push({-1*w,v});
				}
			}
		}
		trueans=min(trueans,ans);
	}
	cout<<trueans<<"\n";
	
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
