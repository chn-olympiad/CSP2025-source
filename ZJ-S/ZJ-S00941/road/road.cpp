#include <bits/stdc++.h>
using namespace std;
#define int long long
/*struct info{
	int u,v,w;
};*/
vector<pair<int,int> > G[10004];
//vector<info> G;
int addG[10004];
int c[10004];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int n,m,k;bool vis[10004];
int solve(){
	int edgenum=0,edgesum=0;
	pq.push(make_pair(0,1));
	while(!pq.empty() && edgenum<n-1){
		int tt=pq.top().first;
		int u=pq.top().second;pq.pop();
		//cout<<u<<endl;
		if(vis[u]) continue;
		edgesum+=tt;
		vis[u]=1;
		for(int t=0;t<G[u].size();t++){
			int v=G[u][t].first,w=G[u][t].second;
			if(vis[v]) continue;
			pq.push(make_pair(w,v));
		}
	}
	return edgesum;
}
namespace TEST2{int GG[1003][1003];
	int solve22(){
		int edgenum=0,edgesum=0;
		pq.push(make_pair(0,1));
		while(!pq.empty() && edgenum<n-1){
			int tt=pq.top().first;
			int u=pq.top().second;pq.pop();
			//cout<<"u: "<<u<<" w: "<<tt<<endl;
			if(vis[u]) continue;
			edgesum+=tt;
			vis[u]=1;
			for(int v=1;v<=n;v++){
				int w=GG[u][v];
				if(vis[v]||GG[u][v]>1e18) continue;
				//cout<<u<<' '<<v<<' '<<w<<endl;
				pq.push(make_pair(w,v));
			}
		}
		return edgesum;
	}
	void solve2(){
		memset(GG,0x2f,sizeof(GG));
		for(int i=1,u,v,w;i<=m;i++){
			cin>>u>>v>>w;
			GG[u][v]=GG[v][u]=w;
		}
		int ans=0;
		for(int j=1;j<=k;j++){//puts("??????????");
			cin>>c[j];ans=min(c[j],ans);
			for(int kk=1;kk<=n;kk++){
				cin>>addG[kk];
			}
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					GG[u][v]=GG[v][u]=min(GG[u][v],addG[u]+addG[v]);
				}
			}
		}
		cout<<ans+TEST2::solve22()<<endl;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(n<=1005 && k!=0){
		TEST2::solve2();
		return 0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		//info t;t.u=u,t.v=v,t.w=w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	cout<<solve()<<endl;
	return 0;
}

