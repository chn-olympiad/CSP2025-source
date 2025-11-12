#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
int n,m,k;
long long ans=LONG_LONG_MAX;
int u,v,t;
long long a[N][N],c[N],w[N][N];
long long dist[N];
map<pair<int,int>,long long> mp;
vector<pair<int,long long> > g[N];
void dijkstra(int x){
	dist[x]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.emplace(make_pair(dist[x],x));
	while(q.size()){
		pair<int,int> t=q.top();
		x=t.second;
		int d=t.first;
		q.pop();
		if(dist[x]<d) continue;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i].first;
			int z=g[x][i].second;
			if(dist[y]>dist[x]+z){
				dist[y]=dist[x]+z;
				q.emplace(make_pair(dist[y],y));
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(c,0x7f,sizeof c);
	memset(w,0x7f,sizeof w);
	memset(a,0x7f,sizeof a);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	if(k==0){ //1-4 
		for(int i=1;i<=m;i++){
			cin>>u>>v>>t;
			g[u].emplace_back(make_pair(v,t));
			g[v].emplace_back(make_pair(u,t));
		}	
		for(int i=1;i<=n;i++){	
			memset(dist,0x7f,sizeof dist);
			dijkstra(i);
			long long sum=0;
			for(int j=1;j<=n;j++) sum+=dist[j];
			ans=min(sum,ans);
		}
		cout<<ans;
		return 0;
	}
	//////////////////////// 分界线 
	//特殊性质A 
	for(int i=1;i<=m;i++){
		cin>>u>>v>>t;
		w[v][u]=w[u][v]=t;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=n;j++){
			if(i!=j){
				long long w1=min(a[i][j],a[j][i]);
				if(w[i][j]!=0x7f7f7f7f7f7f7f7f) w1=min(w1,w[i][j]);
				g[i].emplace_back(make_pair(j,w1));
				g[j].emplace_back(make_pair(i,w1));
			}
		}
	}
	for(int i=1;i<=n;i++){	
		memset(dist,0x7f,sizeof dist);
		dijkstra(i);
		long long sum=0;
		for(int j=1;j<=n;j++) sum+=dist[j];
		ans=min(sum,ans);
	}
	cout<<ans;
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/

/*7 10 0
1 2 2
1 3 5
1 4 3
2 3 4
2 4 3
3 5 6
3 7 2
4 6 10 4 7 7
5 6 1*/
