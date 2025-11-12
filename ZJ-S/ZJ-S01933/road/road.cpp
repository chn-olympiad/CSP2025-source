#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+7,M=300,inf=1e18,mod=1e9+7;
int n,m,k,c[N],a[20][N],U[N],V[N],W[N];
int fa[N];
vector<PII> g[N];
int find(int x){
	//cout<<x<<" "<<fa[x]<<"\n";
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	return fa[x];         
}
priority_queue<PII> q;
int solve(){
	int nn=n+k,mm=m;
	for(int u=1;u<=k;u++){
		for(int v=1;v<=n;v++){
			int w=0;
			U[++mm]=u;
			V[mm]=v;
			W[mm]=a[u][v];
//			g[u].push_back({v,w});
//			g[v].push_back({u,w});
		}
	}
	for(int i=1;i<=mm;i++){
		q.push({-W[i],i});
	}
	for(int i=1;i<=nn;i++)fa[i]=i;
	int cnt=0,ans=0;
//	while(!q.empty()){
//		cout<<U[q.top().second]<<" "<<V[q.top().second]<<"\n";
//		q.pop();
//	}
	while(cnt<nn-1){
		int auv=q.top().second;
		//cout<<0<<"&\n";
		//cout<<fa[4]<<" "<<fa[3]<<"\n";
		int ru=find(U[auv]),rv=find(V[auv]);
		if(ru!=rv){
			fa[ru]=rv;
			ans+=W[auv];
			cnt++;
		}
		q.pop();
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		U[i]=u,V[i]=v;
		W[i]=w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	} 
//	for(int i=1;i<=k;i++){
//		cin>>c[i];
//		for(int j=1;j<=n;j++){
//			cin>>a[i][j];
//		}
//	}
	cout<<solve();
	return 0;
} 
/*
6 7 0
1 3 1
3 6 2
6 2 4
5 4 2
1 5 5
2 5 3
4 1 3
*/
